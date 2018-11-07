#include "player.h"
#include "state.h"
#include "maskBitmaps.h"
#include "nonMaskBitmaps.h"
#include "strings.h"
#include "renderer.h"
#include "tileFloor.h"
#include "util.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

const uint8_t PLAYER_VELOCITY = 2;
const uint8_t CAST_TIMEOUT = 8;

const uint8_t PROGMEM playerSpriteIndexAndMirror[] = {
    // LEFT
    0, 0,
    // RIGHT
    0, MIRROR_HORIZONTAL,
    // UP
    2, 0,
    // DOWN
    3, 0
};

bool Player::isOnSolidTile() {
    return !TileFloor::isWalkable(TileFloor::getTileAt(x + 8, y + 8));
}

void Player::updateWalk(uint8_t frame) {
    if (State::gameState.wormCount > 0 && arduboy.pressed(A_BUTTON)) {
        cursorX = x;
        cursorY = y + 18;
        currentUpdate = &Player::updateScanning;
        currentRender = &Player::renderScanning;
        return;
    }

    int16_t newX = x;
    int16_t newY = y;

    if (arduboy.pressed(DOWN_BUTTON)) {
        newY += PLAYER_VELOCITY;
    }

    if (arduboy.pressed(UP_BUTTON)) {
        newY -= PLAYER_VELOCITY;
    }

    if (arduboy.pressed(LEFT_BUTTON)) {
        newX -= PLAYER_VELOCITY;
    }

    if (arduboy.pressed(RIGHT_BUTTON)) {
        newX += PLAYER_VELOCITY;
    }

    moveTo(newX, newY);

    if (isOnSolidTile()) {
        undoMove();
    }

    movedThisFrame = x != prevX || y != prevY;
}

void Player::renderWalk(uint8_t frame) {
    const uint8_t* offset = playerSpriteIndexAndMirror + (dir * 2);
    uint8_t spriteIndex = pgm_read_byte(offset);
    MirrorMode mirror = (MirrorMode)pgm_read_byte(offset + 1);

    if (movedThisFrame && ((frame / 6) % 2) == 0) {
        if (dir == LEFT || dir == RIGHT) {
            ++spriteIndex;
        } else {
            mirror = MIRROR_HORIZONTAL;
        }
    }

    renderer.drawPlusMask(x, y, player_plus_mask, spriteIndex, mirror);
}

void Player::updateScanning(uint8_t frame) {
    if (!arduboy.pressed(A_BUTTON)) {
        TileDef tile = TileFloor::getTileAt(cursorX + 4, cursorY + 4);

        if (TileFloor::isFishable(tile)) {
            castCount = 0;
            currentUpdate = &Player::updateCast;
            currentRender = &Player::renderCast;
        } else {
            currentUpdate = &Player::updateWalk;
            currentRender = &Player::renderWalk;
        }

        return;
    }

    if (arduboy.pressed(DOWN_BUTTON)) {
        cursorY += PLAYER_VELOCITY;
    }

    if (arduboy.pressed(UP_BUTTON)) {
        cursorY -= PLAYER_VELOCITY;
    }

    if (arduboy.pressed(LEFT_BUTTON)) {
        cursorX -= PLAYER_VELOCITY;
    }

    if (arduboy.pressed(RIGHT_BUTTON)) {
        cursorX += PLAYER_VELOCITY;
    }
}

void Player::renderScanning(uint8_t frame) {
    renderWalk(frame);
    renderer.drawOverwrite(cursorX, cursorY, cursor_tiles, 0, 0, Xor);
}

void Player::updateCast(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON)) {
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;

        return;
    }

    if (frame != 60) {
        return;
    }

    castCount += 1;

    if (castCount == CAST_TIMEOUT) {
        /* State::gameState.wormCount -= 1; */
        /* State::saveToEEPROM(); */

        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;

        return;
    }


    FishType fishType = getFishThatBit();

    if (fishType != FishType::UNSET) {
        LOGV(static_cast<int8_t>(fishType));
        Fish::loadFish(fishType, currentFish);
        reelLevel = WIDTH / 2;
        currentUpdate = &Player::updateReel;
        currentRender = &Player::renderReel;
    }
}

uint8_t Player::getPointsForFish(Fish& fish) {
    uint8_t hour = State::getCurrentHour();

    if (hour < fish.minHour || hour > fish.maxHour) {
        return 0;
    }

    if (x < fish.minX || x > fish.maxX) {
        return 0;
    }

    if (fish.baitPreferences[static_cast<uint8_t>(currentBait)] == 0) {
        return 0;
    }

    return fish.ratio;
}

FishType Player::getFishThatBit() {
    Fish fish;
    uint8_t diceRollIndex = 0;
    uint8_t maxPoints = 0;
    uint8_t candidateFishes = 0;

    for (uint8_t f = 0; f < static_cast<int8_t>(FishType::NUM_FISH); ++f) {
        FishType fishType = static_cast<FishType>(f);

        Fish::loadFish(fishType, fish);

        uint8_t points = getPointsForFish(fish);

        if (points > 0) {
            maxPoints += points;
            candidateFishes += 1;
            fishDiceRoll[diceRollIndex++].type = fishType;
            fishDiceRoll[diceRollIndex++].points = points;
        }
    }


    // TODO: the +5 is the "no fish bites buffer"
    // this buffer needs to scale with the size of maxPoints
    uint8_t roll = random(0, maxPoints + maxPoints * 3);
    
    if (roll >= maxPoints) {
        return FishType::UNSET;
    }


    uint8_t currentPoints = 0;
    for (uint8_t fr = 0; fr < candidateFishes; ++fr) {
        if (roll >= currentPoints && roll < currentPoints + fishDiceRoll[fr].points) {
            return fishDiceRoll[fr].type;
        }
        currentPoints += fishDiceRoll[fr].points;
    }
}

void Player::renderCast(uint8_t frame) {
    renderWalk(frame);
    renderer.drawOverwrite(cursorX, cursorY, bobber_tiles, 0, 0, Xor);
}

void Player::updateReel(uint8_t frame) {
    if (frame % 30 == 0) {
        reelLevel = max(reelLevel - 7, 0);
    }

    if (arduboy.justPressed(A_BUTTON)) {
        reelLevel = min(WIDTH - 2, reelLevel + 5);
    }

    if (reelLevel == 0) {
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;
    } else if (reelLevel == WIDTH - 2) {
        State::gameState.fishCount += 1;
        State::saveToEEPROM();

        announceFishCount = 60;
        currentUpdate = &Player::updateGetFish;
        currentRender = &Player::renderGetFish;
    }
}

void Player::renderReel(uint8_t frame) {
    renderWalk(frame);

    renderer.pushTranslate(0, 0);

    // white background to get rid of anything else there
    renderer.fillRect(0, HEIGHT - 4, WIDTH, 4, WHITE);

    // black progress bar at the current reel level
    renderer.fillRect(0, HEIGHT - 4, reelLevel, 4, BLACK);

    // border to frame it all
    renderer.drawRect(0, HEIGHT - 4, WIDTH, 4, BLACK);

    renderer.popTranslate();
}

void Player::updateGetFish(uint8_t frame) {
    announceFishCount -= 1;

    if (announceFishCount == 0) {
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;
    }
}

const uint8_t* const PROGMEM fishStrings[] = {
    goldfish_string,
    shark_string
};

void Player::renderGetFish(uint8_t frame) {
    renderWalk(frame);
    const uint8_t* fishString = static_cast<const uint8_t*>(pgm_read_ptr(fishStrings + static_cast<int8_t>(currentFish.type)));

    renderer.pushTranslate(0, 0);
    renderer.fillRect(0, HEIGHT- 6, WIDTH, 6, BLACK);
    renderer.drawString(0, HEIGHT - 5, fishString);
    renderer.popTranslate();
}

void Player::update(uint8_t frame) {
    (this->*currentUpdate)(frame);
}

void Player::render(uint8_t frame) {
    (this->*currentRender)(frame);
}

void Player::onGetWorm(Worm& worm) {
    if (worm.isSpawned && State::gameState.wormCount < 99) {
        State::gameState.wormCount +=1;
        State::saveToEEPROM();
    }
}

Direction Player::determineDirection(int16_t px, int16_t py, int16_t x, int16_t y, Direction prevDir) {
    if (px == x && py == y) {
        return prevDir;
    }

    if (px == x) {
        if (py > y) {
            return UP;
        }
        return DOWN;
    } else {
        if (px > x) {
            return LEFT;
        }
        return RIGHT;
    }
}

void Player::moveTo(int16_t newX, int16_t newY, boolean resetPrev) {
    if (resetPrev) {
        prevX = newX;
        prevY = newY;
    } else if (prevX != x || prevY != y) {
        prevX = x;
        prevY = y;
    }

    x = newX;
    y = newY;

    dir = determineDirection(prevX, prevY, x, y, dir);
}

void Player::undoMove() {
    x = prevX;
    y = prevY;
}
