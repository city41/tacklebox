#include "player.h"
#include "../renderer.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

const uint8_t PLAYER_VELOCITY = 2;

void Player::render(uint8_t frame) {
    renderer.drawPlusMask(WIDTH / 2 - 4, HEIGHT / 2 - 8, player_plus_mask, 0);

#ifdef DRAW_HITBOXES
    renderer.drawRect(x, y, w, h, BLACK);
#endif
}

void Player::update(uint8_t frame) {
    int16_t newX = x, newY = y;

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
}
