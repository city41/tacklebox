#include "player.h"
#include "../maskBitmaps.h"
#include "../nonMaskBitmaps.h"
#include "../renderer.h"
#include "../tileFloor.h"
#include "../overworld.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

const uint8_t PLAYER_VELOCITY = 2;

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
    TileDef tile = TileFloor::getTileAt(x, y);

    return tile == Stone || tile == Water;
}

void Player::updateWalk(uint8_t frame) {
    if (arduboy.pressed(A_BUTTON)) {
        holdACount += 1;
        if (holdACount == 50) {
            cursorX = x;
            cursorY = y + 18;
            currentUpdate = &Player::updateScanning;
            currentRender = &Player::renderScanning;
            return;
        }
    } else {
        holdACount = 0;
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

        if (tile == Water) {
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

    castCount += 1;

    if (castCount == 60) {
        reelLevel = WIDTH / 2;
        currentUpdate = &Player::updateReel;
        currentRender = &Player::renderReel;
    }
}

void Player::renderCast(uint8_t frame) {
    renderWalk(frame);
    renderer.drawOverwrite(cursorX, cursorY, bobber_tiles, 0, 0, Xor);
}

void Player::updateReel(uint8_t frame) {
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

void Player::update(uint8_t frame) {
    (this->*currentUpdate)(frame);
}

void Player::render(uint8_t frame) {
    (this->*currentRender)(frame);
}

void Player::onGetWorm(Worm& worm) {
    if (worm.isSpawned) {
        wormCount +=1;
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
