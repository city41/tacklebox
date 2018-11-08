#include "shop.h"
#include "renderer.h"
#include "strings.h"
#include "nonMaskBitmaps.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

uint8_t Shop::mainMenuCurrentRow = 0;
Shop::UpdatePtr Shop::currentUpdate = &Shop::updateMainMenu;
Shop::RenderPtr Shop::currentRender = &Shop::renderMainMenu;

void Shop::update(uint8_t frame) {
    Shop::currentUpdate(frame);
}

void Shop::render(uint8_t frame) {
    Shop::currentRender(frame);
}

void Shop::updateMainMenu(uint8_t frame) {
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
    renderer.drawOverwrite(34, 10 + Shop::mainMenuCurrentRow * 10, squareIcon_tiles, 0);
    renderer.drawString(40, 10, buy_string);
    renderer.drawString(40, 20, sell_string);
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
}

void Shop::renderSell(uint8_t frame) {
    renderer.drawString(40, 20, tempSell_string);
}
