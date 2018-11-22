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

    if (hour >= 12) {
        renderer.drawPlusMask(44, clockY, pm_plus_mask, 0);
    }

    if (hour == 0) {
        hour = 12;
    }

    if (hour > 12) {
        hour -= 12;
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
    renderer.fillRect(0, 0, 50, 8, BLACK);

    const uint8_t* baitBmp = reinterpret_cast<const uint8_t*>(pgm_read_ptr(baitBmps + static_cast<int8_t>(player.currentBait)));

    renderer.drawPlusMask(1, 0, baitBmp, 0, 0, Invert);
    renderer.drawNumber(12, clockY, State::gameState.baitCounts[static_cast<int8_t>(player.currentBait)]);

    drawClock();
}

