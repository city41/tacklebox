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

void Player::render(uint8_t frame, int16_t cornerX, int16_t cornerY) {
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

    int16_t renderX, renderY;

    if (x < WIDTH / 2) {
        renderX = x;
    } else if (x > MAP_WIDTH_PX - WIDTH / 2) {
        renderX = x - (MAP_WIDTH_PX - WIDTH);
    } else {
        renderX = WIDTH / 2;
    }

    if (y < HEIGHT / 2) {
        renderY = y;
    } else if (y > MAP_HEIGHT_PX - HEIGHT / 2) {
        renderY = y - (MAP_HEIGHT_PX - HEIGHT);
    } else {
        renderY = HEIGHT / 2;
    }

    renderer.drawPlusMask(renderX - 8, renderY - 8, player_plus_mask, spriteIndex, mirror);

    if (scanning) {
        renderer.drawOverwrite(cursorX - cornerX, cursorY - cornerY, cursor_tiles, 0, 0, Xor);
    }
}

bool Player::isOnSolidTile() {
    TileDef tile = TileFloor::getTileAt(x, y);

    return tile == Stone || tile == Water;
}

void Player::update(uint8_t frame) {

    if (arduboy.pressed(A_BUTTON)) {
        if (holdACount == 49) {
            cursorX = x;
            cursorY = y + 18;
        }

        holdACount = min(holdACount + 1, 50);
    } else {
        holdACount = 0;
    }

    scanning = holdACount == 50;

    int16_t newX = scanning ? cursorX : x;
    int16_t newY = scanning ? cursorY : y;

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

    if (scanning) {
        cursorX = newX;
        cursorY = newY;
    } else {
        moveTo(newX, newY);

        if (isOnSolidTile()) {
            undoMove();
        }
        movedThisFrame = x != prevX || y != prevY;
    }

}

void Player::onGetWorm(Worm& worm) {
    if (worm.isSpawned) {
        wormCount +=1;
    }
}
