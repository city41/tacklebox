#include "shop.h"
#include "renderer.h"
#include "strings.h"
#include "nonMaskBitmaps.h"
#include "maskBitmaps.h"
#include "fishType.h"
#include "fish.h"
#include "state.h"
#include "animation.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

uint8_t Shop::mainMenuCurrentRow = 0;
Shop::UpdatePtr Shop::currentUpdate = &Shop::updateMainMenu;
Shop::RenderPtr Shop::currentRender = &Shop::renderMainMenu;


const uint8_t PROGMEM shopOwnerDurations[] = {
    20, 0, 5, 1, 5, 2, 5, 3, 255
};

Animation shopOwnerAnimation(shopOwnerDurations);

void Shop::onEnter() {
    shopOwnerAnimation.reset();
}

void Shop::update(uint8_t frame) {
    Shop::currentUpdate(frame);
}

void Shop::render(uint8_t frame) {
    Shop::currentRender(frame);
}

void Shop::updateMainMenu(uint8_t frame) {
    shopOwnerAnimation.update();

    if (arduboy.justPressed(DOWN_BUTTON)) {
        Shop::mainMenuCurrentRow = 1;
    }

    if (arduboy.justPressed(UP_BUTTON)) {
        Shop::mainMenuCurrentRow = 0;
    }

    if (arduboy.justPressed(A_BUTTON)) {
        if (Shop::mainMenuCurrentRow == 0) {
            Shop::currentUpdate = &Shop::updateBuy;
            Shop::currentRender = &Shop::renderBuy;
        } else {
            Shop::currentUpdate = &Shop::updateSell;
            Shop::currentRender = &Shop::renderSell;
        }
    }
}

void Shop::renderMainMenu(uint8_t frame) {
    // white frame
    renderer.fillRect(13, 19, 103, 1, WHITE);
    renderer.fillRect(116, 20, 1, 40, WHITE);
    renderer.fillRect(12, 20, 1, 40, WHITE);
    renderer.fillRect(13, HEIGHT - 4, 103, 1, WHITE);

    renderer.drawOverwrite(20, 2, shopOwner_tiles, shopOwnerAnimation.currentFrame);

    renderer.drawOverwrite(34, 30 + Shop::mainMenuCurrentRow * 10, squareIcon_tiles, 0);
    renderer.drawString(40, 30, buy_string);
    renderer.drawString(40, 40, sell_string);
}

void Shop::updateBuy(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON)) {
        Shop::currentUpdate = &Shop::updateMainMenu;
        Shop::currentRender = &Shop::renderMainMenu;
    }
}

void Shop::renderBuy(uint8_t frame) {
    renderer.drawString(40, 20, tempBuy_string);
}

void Shop::updateSell(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON)) {
        Shop::currentUpdate = &Shop::updateMainMenu;
        Shop::currentRender = &Shop::renderMainMenu;
    }

    if (arduboy.justPressed(A_BUTTON)) {
        State::sellAllFish();
        Shop::currentUpdate = &Shop::updateMainMenu;
        Shop::currentRender = &Shop::renderMainMenu;
    }
}

void Shop::renderSell(uint8_t frame) {
    uint16_t moneyAmount = 0;

    Fish fish;
    for (uint8_t f = 0; f < static_cast<int8_t>(FishType::NUM_FISH); ++f) {
        Fish::loadFish(static_cast<FishType>(f), fish);
        moneyAmount += State::gameState.currentFishCount[f] * fish.value;
    }

    renderer.drawString(20, 20, tempSell_string);
    renderer.drawNumber(20, 30, moneyAmount);
}
