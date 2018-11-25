#include "dialogUtils.h"
#include "renderer.h"
#include "animation.h"
#include "state.h"
#include "maskBitmaps.h"
#include "baitBitmaps.h"

extern Renderer renderer;

const uint8_t PROGMEM personEnterDurations[] = {
    20, 0, 5, 1, 5, 2, 5, 3, 255
};

Animation personEnterAnimation(personEnterDurations);

void DialogUtils::renderFrame(const uint8_t* bmp) {
    personEnterAnimation.update();

    // white frame
    renderer.fillRect(13, 19, 103, 1, WHITE);
    renderer.fillRect(116, 20, 1, 42, WHITE);
    renderer.fillRect(12, 20, 1, 42, WHITE);
    renderer.fillRect(13, HEIGHT - 2, 103, 1, WHITE);

    renderer.drawOverwrite(20, 2, bmp, personEnterAnimation.currentFrame);
}

void DialogUtils::reset() {
    personEnterAnimation.reset();
}

void DialogUtils::renderMoneyInCorner() {
    renderer.drawPlusMask(WIDTH - 42, 0, currencySymbol_plus_mask, 0);
    renderer.drawNumber(WIDTH - 36, 1, State::gameState.money);
}

