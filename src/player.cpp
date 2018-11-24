#include <Arduboy2.h>
#include "player.h"
#include "state.h"
#include "maskBitmaps.h"
#include "nonMaskBitmaps.h"
#include "strings.h"
#include "renderer.h"
#include "tileFloor.h"
#include "util.h"
#include "fishTemplates.h"
#include "enumUtils.h"
#include "world.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

const uint8_t PLAYER_VELOCITY = 2;
const uint8_t CAST_TIMEOUT = 8;
const uint8_t ANNOUNCE_FISH_COUNT = 120;


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

void Player::reset() {
    moveTo(STARTING_X, STARTING_Y);
    currentBait = BaitType::Worm;
    currentCollectionRow = 0;
}

bool Player::isOnSolidTile() {
    return !TileFloor::isWalkable(TileFloor::getTileAt(x + 8, y + 14));
}

/**
 * The player has just started scanning,
 * based on the way the player is facing, start the cursor
 * in front of the player
 */
void Player::placeCursorBasedOnDir() {
    switch (dir) {
        case UP:
            cursorX = x + 4;
            cursorY = y - 8;
            break;
        case DOWN:
            cursorX = x + 4;
            cursorY = y + 18;
            break;
        case LEFT:
            cursorY = y + 8;
            cursorX = x - 10;
            break;
        case RIGHT:
            cursorY = y + 8;
            cursorX = x + 18;
            break;
    }
}

void Player::updateWalk(uint8_t frame) {
    if (State::gameState.baitCounts[static_cast<int8_t>(currentBait)] > 0 && arduboy.pressed(A_BUTTON)) {
        placeCursorBasedOnDir();

        currentUpdate = &Player::updateScanning;
        currentRender = &Player::renderScanning;
        return;
    }

    if (arduboy.justPressed(B_BUTTON)) {
        areYouSure = false;
        menuRow = MenuRow::COLLECTION;
        currentUpdate = &Player::updateMenu;
        currentRender = &Player::renderMenu;
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

    if (movedThisFrame && ((frame / 10) % 2) == 0) {
        if (dir == LEFT || dir == RIGHT) {
            ++spriteIndex;
        } else {
            mirror = MIRROR_HORIZONTAL;
        }
    }

    renderer.drawPlusMask(x, y, player_plus_mask, spriteIndex, mirror);

    if (saveToastCount > 0) {
        saveToastCount -= 1;
        renderer.pushTranslate(0, 0);
        renderer.fillRect(0, HEIGHT - 5, WIDTH, 5, BLACK);
        renderer.drawString(0, HEIGHT - 4, gameSaved_string);
    }
}

void Player::updateMenu(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON)) {
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;
        return;
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
        menuRow = next(menuRow);
    }
    
    if (arduboy.justPressed(UP_BUTTON)) {
        menuRow = prev(menuRow);
    }


    if (arduboy.justPressed(RIGHT_BUTTON)) {
        currentBait = next(currentBait);
    }

    if (arduboy.justPressed(LEFT_BUTTON)) {
        currentBait = prev(currentBait);
    }

    if (arduboy.justPressed(A_BUTTON)) {
        switch (static_cast<MenuRow>(menuRow)) {
            case MenuRow::COLLECTION:
                currentUpdate = &Player::updateCollection;
                currentRender = &Player::renderCollection;
                break;
            case MenuRow::SAVE:
                State::saveToEEPROM();
                saveToastCount = 60;
                currentUpdate = &Player::updateWalk;
                currentRender = &Player::renderWalk;
                break;
            case MenuRow::SFX:
                Arduboy2Audio::toggle();
                Arduboy2Audio::saveOnOff();
                break;
            case MenuRow::DELETE:
                currentUpdate = &Player::updateAreYouSure;
                currentRender = &Player::renderAreYouSure;
                break;
        }
    }
}

void Player::renderMenu(uint8_t frame) {
    renderer.pushTranslate(10, 0);
    renderer.fillRect(0, 0, WIDTH / 2 - 20, HEIGHT, BLACK);

    // bait
    const uint8_t baitY = 4;
    renderer.drawPlusMask(2, baitY, wormIcon_plus_mask, 0, 0, Invert);
    renderer.drawPlusMask(12, baitY, grub_plus_mask, 0, 0, Invert);
    renderer.drawPlusMask(22, baitY, shrimp_plus_mask, 0, 0, Invert);
    renderer.drawPlusMask(32, baitY, meat_plus_mask, 0, 0, Invert);

    // bait cursor
    renderer.drawOverwrite(4 + static_cast<int8_t>(currentBait) * 10, baitY + 10,  squareIcon_tiles, 0);

    // menu items
    const uint8_t startY = 24;
    const uint8_t spacing = 7;

    renderer.drawString(6, startY, collection_string);
    renderer.drawString(6, startY + spacing * 1, save_string);

    const uint8_t* sfxString = Arduboy2Audio::enabled() ? sfxOn_string : sfxOff_string;
    renderer.drawString(6, startY + spacing * 2, sfxString);

    renderer.drawString(6, startY + spacing * 3, delete_string);

    renderer.drawOverwrite(1, startY + static_cast<int8_t>(menuRow) * spacing,  squareIcon_tiles, 0);

    // money
    renderer.drawPlusMask(6, startY + spacing * 4 + 3, currencySymbol_plus_mask, 0);
    renderer.drawNumber(12, startY + spacing * 4 + 4, State::gameState.money);
    renderer.popTranslate();
}

void Player::updateAreYouSure(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON)) {
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;
        return;
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
        areYouSure = true;
    }
    
    if (arduboy.justPressed(UP_BUTTON)) {
        areYouSure = false;
    }

    if (arduboy.justPressed(A_BUTTON)) {
        if (areYouSure) {
            State::clearEEPROM();
            State::load();
            moveTo(STARTING_X, STARTING_Y);
            currentUpdate = &Player::updateWalk;
            currentRender = &Player::renderWalk;
        } else {
            currentUpdate = &Player::updateWalk;
            currentRender = &Player::renderWalk;
        }
    }
}

void Player::renderAreYouSure(uint8_t frame) {
    renderer.pushTranslate(10, 0);
    renderer.fillRect(0, 0, WIDTH / 2 - 20, HEIGHT, BLACK);

    renderer.drawString(6, 20, really_string);
    renderer.drawString(6, 26, delete_string);
    renderer.drawString(6, 32, save_string);
    renderer.drawOverwrite(27, 32, questionMark_tiles, 0);

    renderer.drawString(10, 44, no_string);
    renderer.drawString(10, 50, yes_string);

    renderer.drawOverwrite(6, 44 + static_cast<int8_t>(areYouSure) * 6,  squareIcon_tiles, 0);

    renderer.popTranslate();
}

void Player::updateCollection(uint8_t frame) {
    if (arduboy.justPressed(DOWN_BUTTON)) {
        currentCollectionRow = min(static_cast<int8_t>(FishType::COUNT) - 2, currentCollectionRow + 1);
        Sfx::menuTick();
    }

    if (arduboy.justPressed(UP_BUTTON)) {
        currentCollectionRow = max(0, currentCollectionRow - 1);
        Sfx::menuTick();
    }

    if (arduboy.justPressed(RIGHT_BUTTON) || arduboy.justPressed(LEFT_BUTTON)) {
        currentCollectionColumn = next(currentCollectionColumn);
        Sfx::menuTick();
    }

    if (arduboy.justPressed(B_BUTTON)) {
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;
    }
}

void Player::renderCollection(uint8_t frame) {
    renderer.pushTranslate(0, 0);
    renderer.fillRect(18, 10, WIDTH - 36, HEIGHT - 5, BLACK);

    const uint8_t* headerStr = currentCollectionColumn == CollectionColumn::Quantity ? quantity_string : length_string;
    renderer.drawString(22, 12, headerStr);

    const uint8_t spacing = 15;
    const uint8_t startY = 17;

    Fish fish;

    for (uint8_t f = currentCollectionRow; f < static_cast<int8_t>(FishType::COUNT) && f < currentCollectionRow + 3; ++f) {
        uint8_t offset = f - currentCollectionRow;
        renderer.drawNumber(22, startY + spacing * offset + 7, f + 1);

        if (State::gameState.acquiredFish[f]) {
            const uint8_t* fishString = static_cast<const uint8_t*>(pgm_read_ptr(fish_templates_16t + f * NUM_16T_PROPS + 2));
            const uint8_t* fishBmp = static_cast<const uint8_t*>(pgm_read_ptr(fish_templates_16t + f * NUM_16T_PROPS + 3));

            const int16_t* numArray = (
                    currentCollectionColumn == CollectionColumn::Quantity ? State::gameState.currentFishCount
                    : State::gameState.bestLength
            );

            // show a checkmark if the user has caught the biggest possible fish
            if (currentCollectionColumn == CollectionColumn::Length) {
                Fish::loadFish(static_cast<FishType>(f), fish);

                if (numArray[f] >= fish.maxLength) {
                    renderer.drawString(88, startY + spacing * offset + 7, checkmark_string);
                }
            }

            renderer.drawNumber(92, startY + spacing * offset + 9, numArray[f]);
            renderer.drawOverwrite(44, startY + spacing * offset, fishBmp, 0);
            renderer.drawString(44, startY + spacing * offset + 9, fishString);
        } else {
            renderer.drawOverwrite(44, startY + spacing * offset + 7, questionMark_tiles, 0);
        }
    }

    if (currentCollectionRow > 0) {
        renderer.drawPlusMask(WIDTH - 26, startY + 2, arrow_plus_mask, 1);
    }

    if (currentCollectionRow < static_cast<int8_t>(FishType::COUNT) - 2) {
        renderer.drawPlusMask(WIDTH - 26, HEIGHT - 4, arrow_plus_mask, 0);
    }
}

void Player::updateScanning(uint8_t frame) {
    if (!arduboy.pressed(A_BUTTON)) {
        TileDef tile = TileFloor::getTileAt(cursorX + 4, cursorY + 4);

        if (TileFloor::isFishable(tile)) {
            castCount = 0;

            State::gameState.baitCounts[static_cast<int8_t>(currentBait)] -= 1;

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

    // if the player only has the beginner pole, it has a limited casting range
    // the pro pole can cast anywhere on the screen
    // why? only pro pole can cast into deep water
    if (!State::gameState.hasProPole) {
        cursorY = min(max(cursorY, y - 16), y + 24);
        cursorX = min(max(cursorX, x - 16), x + 24);
    }

    // make sure cursor doesn't leave the map
    cursorX = max(min(MAP_WIDTH_PX - 16, cursorX), 0);
    cursorY = max(min(MAP_HEIGHT_PX - 8, cursorY), 0);
}

void Player::renderScanning(uint8_t frame) {
    uint8_t spriteIndex;
    uint8_t poleIndex = 0;
    MirrorMode mirror = NO_MIRROR;
    MirrorMode poleMirror = NO_MIRROR;
    int16_t poleX;
    int16_t poleY;

    switch (dir) {
        case LEFT:
            spriteIndex = 4;
            poleY = y - 4;
            poleX = x + 14;
            break;
        case RIGHT:
            spriteIndex = 4;
            mirror = MIRROR_HORIZONTAL;
            poleMirror = MIRROR_HORIZONTAL;
            poleY = y - 4;
            poleX = x - 12;
            break;
        case UP:
            spriteIndex = 6;
            poleIndex = 2;
            poleMirror = MIRROR_VERTICAL;
            poleY = y + 12;
            poleX = x + 1;
            break;
        case DOWN:
            spriteIndex = 3;
            poleIndex = 2;
            poleY = y - 12;
            poleX = x;
            mirror = MIRROR_HORIZONTAL;
            poleMirror = MIRROR_HORIZONTAL;
            break;
    }

    renderer.drawPlusMask(x, y, player_plus_mask, spriteIndex, mirror);
    renderer.drawPlusMask(poleX, poleY, fishingPole_plus_mask, poleIndex, poleMirror);
    renderer.drawOverwrite(cursorX, cursorY, cursor_tiles, 0, 0);
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
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;

        return;
    }

    TileDef tileBeingFished = TileFloor::getTileAt(cursorX + 4, cursorY + 4);

    FishType fishType = getFishThatBit(tileBeingFished == TileDef::PondMiddleDeep);
    LOGV(static_cast<int8_t>(fishType));

    if (fishType != FishType::UNSET) {
        Fish::loadFish(fishType, currentFish);
        reelLevel = WIDTH / 2;

        currentUpdate = &Player::updateReel;
        currentRender = &Player::renderReel;
    }
}

uint8_t Player::getPointsForFish(Fish& fish, bool isDeepWater) {
    uint8_t hour = State::getCurrentHour();

    if (isDeepWater && !fish.deepWater) {
        LOG("fish is not deep water");
        return 0;
    }

    if (hour < fish.minHour || hour > fish.maxHour) {
        LOG("hour out of range");
        return 0;
    }

    LOGV(cursorX);
    if (cursorX < fish.minX || cursorX > fish.maxX) {
        LOG("x out of range");
        return 0;
    }

    if (fish.baitPreferences[static_cast<uint8_t>(currentBait)] == 0) {
        LOG("fish doesnt like the bait");
        return 0;
    }

    return fish.ratio;
}

FishType Player::getFishThatBit(bool isDeepWater) {
    Fish fish;
    uint8_t diceRollIndex = 0;
    uint8_t maxPoints = 0;
    uint8_t candidateFishes = 0;

    for (uint8_t f = 0; f < static_cast<int8_t>(FishType::COUNT); ++f) {
        FishType fishType = static_cast<FishType>(f);

        Fish::loadFish(fishType, fish);

        uint8_t points = getPointsForFish(fish, isDeepWater);
        LOGV(points);

        if (points > 0) {
            maxPoints += points;
            candidateFishes += 1;
            fishDiceRoll[diceRollIndex].type = fishType;
            fishDiceRoll[diceRollIndex].points = points;
            diceRollIndex += 1;
        }
    }


    // TODO: the +5 is the "no fish bites buffer"
    // this buffer needs to scale with the size of maxPoints
    uint8_t roll = random(0, maxPoints + maxPoints * 3);
    
    if (roll >= maxPoints) {
        return FishType::OLDBOOT;
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
    uint8_t spriteIndex;
    uint8_t poleIndex = 0;
    MirrorMode playerMirror = NO_MIRROR;
    MirrorMode poleMirror = NO_MIRROR;
    int16_t poleX = -200;
    int16_t poleY = -200;

    switch (dir) {
        case LEFT:
            spriteIndex = 5;
            poleY = y;
            poleX = x - 10;
            poleMirror = MIRROR_HORIZONTAL;
            break;
        case RIGHT:
            spriteIndex = 5;
            playerMirror = MIRROR_HORIZONTAL;
            poleY = y;
            poleX = x + 10;
            break;
        case UP:
            spriteIndex = 6;
            poleIndex = 2;
            poleMirror = MIRROR_HORIZONTAL;
            poleY = y - 10;
            poleX = x + 6;
            break;
        case DOWN:
            spriteIndex = 3;
            poleIndex = 2;
            poleMirror = MIRROR_VERTICAL;
            poleY = y + 10;
            poleX = x - 1;
            break;
    }

    renderer.drawPlusMask(poleX, poleY, fishingPole_plus_mask, poleIndex, poleMirror);
    renderer.drawPlusMask(x, y, player_plus_mask, spriteIndex, playerMirror);
    renderer.drawOverwrite(cursorX, cursorY, bobber_tiles, static_cast<uint8_t>(frame > 30), 0, Xor);
}

void Player::updateReel(uint8_t frame) {
    if (frame % 30 == 0) {
        reelLevel = max(reelLevel - currentFish.pull, 0);
    }

    if (arduboy.justPressed(A_BUTTON)) {
        Sfx::menuTick();
        uint8_t playerPull = State::gameState.hasProPole ? 15 : 10;
        reelLevel = min(WIDTH - 2, reelLevel + playerPull);
    }

    if (reelLevel == 0) {
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;
    } else if (reelLevel == WIDTH - 2) {
        State::setFishAcquired(currentFish.type);
        State::incrementCurrentCount(currentFish.type);

        currentFish.rollForLength();

        State::setFishLength(currentFish);

        announceFishCount = ANNOUNCE_FISH_COUNT;

        if (currentFish.type == FishType::OLDBOOT) {
            Sfx::buzz();
        } else {
            Sfx::gotFish();
        }

        currentUpdate = &Player::updateGetFish;
        currentRender = &Player::renderGetFish;
    }
}

void Player::renderReel(uint8_t frame) {
    uint8_t spriteIndex;
    uint8_t poleIndex = 1;
    MirrorMode playerMirror = NO_MIRROR;
    MirrorMode poleMirror = NO_MIRROR;
    int16_t poleX;
    int16_t poleY;

    switch (dir) {
        case LEFT:
            spriteIndex = 5;
            poleY = y;
            poleX = x - 11;
            poleMirror = MIRROR_HORIZONTAL;

            if (frame > 50) {
                spriteIndex = 7;
                poleX += 1;
            }
            break;
        case RIGHT:
            spriteIndex = 5;
            playerMirror = MIRROR_HORIZONTAL;
            poleY = y;
            poleX = x + 13;
            if (frame > 50) {
                spriteIndex = 7;
                poleX -= 1;
            }
            break;
        case UP:
            spriteIndex = 6;
            poleIndex = 2;
            poleMirror = MIRROR_HORIZONTAL;
            poleY = y - 10;
            poleX = x + 5;
            if (frame > 50) {
                poleX += 1;
            }
            break;
        case DOWN:
            spriteIndex = 3;
            poleIndex = 2;
            poleMirror = MIRROR_VERTICAL;
            poleY = y + 10;
            poleX = x - 1;
            if (frame > 50) {
                poleX += 1;
            }
            break;
    }

    renderer.drawPlusMask(poleX, poleY, fishingPole_plus_mask, poleIndex, poleMirror);
    renderer.drawPlusMask(x, y, player_plus_mask, spriteIndex, playerMirror);

    renderer.pushTranslate(0, 0);

    // black background to serve as the frame
    renderer.fillRect(29, HEIGHT - 14, WIDTH - 58, 8, BLACK);

    // white background to serve as the empty part
    renderer.fillRect(30, HEIGHT - 13, WIDTH - 60, 6, WHITE);

    // black progress bar at the current reel level
    renderer.fillRect(32, HEIGHT - 12, reelLevel / 2, 4, BLACK);

    renderer.popTranslate();
}

void Player::updateGetFish(uint8_t frame) {
    announceFishCount -= 1;

    if (announceFishCount == 0) {
        currentUpdate = &Player::updateWalk;
        currentRender = &Player::renderWalk;
    }
}


const uint8_t GET_FISH_FRAME_WIDTH = 48;
const uint8_t GET_FISH_FRAME_HEIGHT = 54;

void Player::renderGetFish(uint8_t frame) {
    renderer.fillRect(x - 13, y - 12, GET_FISH_FRAME_WIDTH, GET_FISH_FRAME_HEIGHT, BLACK);
    renderer.fillRect(x - 12, y, GET_FISH_FRAME_WIDTH - 2, 17, WHITE);


    renderer.drawOverwrite(
        x - 13 + (GET_FISH_FRAME_WIDTH / 2 - currentFish.bmpWidth / 2),
        y - 10,
        currentFish.bmp,
        0
    );

    // TODO: make this an Animation
    uint8_t spriteIndex = (announceFishCount > ANNOUNCE_FISH_COUNT - 20 || announceFishCount < 30) ? 8 : currentFish.type == FishType::OLDBOOT ? 10 : 9;
    renderer.drawPlusMask(x, y, player_plus_mask, spriteIndex);

    renderer.drawString(
        x - 13 + (GET_FISH_FRAME_WIDTH / 2 - currentFish.nameLength * 5 / 2),
        y + 20,
        currentFish.nameString
    );


    if (currentFish.type != FishType::OLDBOOT) {
        // draw the size of the fish, centered under its name
        // a bit fiddly since the length of the fish can vary

        // how many characters is the fishes length plus the "cm" label?
        int8_t lengthChars = currentFish.length > 99 ? 5 : currentFish.length > 9 ? 4 : 3;
        int16_t lengthStartX = x - 13 + (GET_FISH_FRAME_WIDTH / 2 - lengthChars * 5 / 2);

        renderer.drawNumber(
                lengthStartX,
                y + 26,
                currentFish.length
                );

        renderer.drawString(
                lengthStartX + lengthChars * (5 - 2) + 1,
                y + 26,
                cm_string
                );

        if (currentFish.length == currentFish.maxLength) {
            renderer.drawString(
                    lengthStartX + lengthChars * 5 + 4,
                    y + 26,
                    checkmark_string
                    );
        }
    }
}

void Player::update(uint8_t frame) {
    (this->*currentUpdate)(frame);
}

void Player::render(uint8_t frame) {
    (this->*currentRender)(frame);
}

void Player::onGetWorm(Worm& worm) {
    if (worm.isSpawned && State::gameState.baitCounts[0] < 254) {
        State::gameState.baitCounts[0] +=1;
        Sfx::purchase();
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
