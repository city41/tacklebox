#include "hud.h"
#include "state.h"
#include "renderer.h"
#include "strings.h"
#include "nonMaskBitmaps.h"
#include "maskBitmaps.h"

extern Renderer renderer;

const uint8_t clockY = 2;

const uint8_t* const PROGMEM baitBmps[] = {
    wormIcon_plus_mask,
    grub_plus_mask,
    shrimp_plus_mask,
    meat_plus_mask
};

void drawClock() {
    uint8_t hour = State::gameState.minute / 60;

    const uint8_t* amPmBmp = hour >= 12 ? pm_plus_mask : am_plus_mask;
    renderer.drawPlusMask(60, clockY, amPmBmp, 0);

    if (hour == 0) {
        hour = 12;
    }

    if (hour > 12) {
        hour -= 12;
    }

    uint8_t hourX = hour < 10 ? 43 : 38;

    renderer.drawNumber(hourX, clockY, hour);

    renderer.drawPlusMask(48, clockY, colon_plus_mask, 0);

    uint8_t minutes = State::gameState.minute % 60 / 5 * 5;

    uint8_t minuteX = 50;

    if (minutes < 10) {
        renderer.drawNumber(minuteX, clockY, 0);
        minuteX = 55;
    }

    renderer.drawNumber(minuteX, clockY, minutes);
}

void Hud::render(Player& player) {
    renderer.fillRect(0, 0, 64, 9, BLACK);

    const uint8_t* baitBmp = reinterpret_cast<const uint8_t*>(pgm_read_ptr(baitBmps + static_cast<int8_t>(player.currentBait)));

    renderer.drawPlusMask(4, 0, baitBmp, 0, 0, Invert);
    renderer.drawNumber(15, clockY, State::gameState.baitCounts[static_cast<int8_t>(player.currentBait)]);

    drawClock();
}

