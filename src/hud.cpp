#include "hud.h"
#include "state.h"
#include "renderer.h"
#include "strings.h"
#include "nonMaskBitmaps.h"
#include "maskBitmaps.h"

extern Renderer renderer;

const uint8_t clockY = 3;

void drawClock() {
    uint8_t hour = State::gameState.minute / 60;

    if (hour > 12) {
        hour -= 12;
        renderer.drawPlusMask(44, clockY + 1, pm_plus_mask, 0);
    }

    uint8_t hourX = hour < 10 ? 27 : 22;

    renderer.drawNumber(hourX, clockY, hour);

    renderer.drawPlusMask(32, clockY, colon_plus_mask, 0);

    uint8_t minutes = State::gameState.minute % 60 / 5 * 5;

    uint8_t minuteX = 34;

    if (minutes < 10) {
        renderer.drawNumber(minuteX, clockY, 0);
        minuteX = 39;
    }

    renderer.drawNumber(minuteX, clockY, minutes);
}

void Hud::render(uint8_t frame, Player& player) {
    renderer.fillRect(0, 0, 50, 10, BLACK);

    renderer.drawOverwrite(3, 1, worm_tiles, 0, 0, Invert);
    renderer.drawNumber(13, 3, State::gameState.wormCount);

    drawClock();
}

