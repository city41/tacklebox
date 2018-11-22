#include "shop.h"
#include "renderer.h"
#include "strings.h"
#include "nonMaskBitmaps.h"
#include "maskBitmaps.h"
#include "fishType.h"
#include "fish.h"
#include "state.h"
#include "animation.h"
#include "enumUtils.h"
#include "baitType.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

ShopMainMenu Shop::mainMenuCurrentRow = ShopMainMenu::Buy;
BuyMenu Shop::buyMenuCurrentRow = BuyMenu::Grub;
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

    // user's current money in upper corner
    renderer.drawPlusMask(WIDTH - 40, 0, currencySymbol_plus_mask, 0);
    renderer.drawNumber(WIDTH - 34, 1, State::gameState.money);

    // user's current grub and shrimp count for reference
    renderer.drawPlusMask(WIDTH - 60, 8, grub_plus_mask, 0, 0, Invert);
    renderer.drawNumber(WIDTH - 48, 10, State::gameState.baitCounts[static_cast<int8_t>(BaitType::Grub)]);

    renderer.drawPlusMask(WIDTH - 40, 8, shrimp_plus_mask, 0, 0, Invert);
    renderer.drawNumber(WIDTH - 28, 10, State::gameState.baitCounts[static_cast<int8_t>(BaitType::Shrimp)]);
}

void Shop::updateMainMenu(uint8_t frame) {
    shopOwnerAnimation.update();

    if (arduboy.justPressed(UP_BUTTON)) {
        Shop::mainMenuCurrentRow = prev(Shop::mainMenuCurrentRow);
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
        Shop::mainMenuCurrentRow = next(Shop::mainMenuCurrentRow);
    }

    if (arduboy.justPressed(A_BUTTON)) {
        if (Shop::mainMenuCurrentRow == ShopMainMenu::Buy) {
            Shop::currentUpdate = &Shop::updateBuy;
            Shop::currentRender = &Shop::renderBuy;
        } else {
            Shop::currentUpdate = &Shop::updateSell;
            Shop::currentRender = &Shop::renderSell;
        }
    }
}

void renderFrame() {
    // white frame
    renderer.fillRect(13, 19, 103, 1, WHITE);
    renderer.fillRect(116, 20, 1, 42, WHITE);
    renderer.fillRect(12, 20, 1, 42, WHITE);
    renderer.fillRect(13, HEIGHT - 2, 103, 1, WHITE);

    renderer.drawOverwrite(20, 2, shopOwner_tiles, shopOwnerAnimation.currentFrame);
}

void Shop::renderMainMenu(uint8_t frame) {
    renderFrame();

    const uint8_t startY = 28;
    const uint8_t spacing = 10;

    renderer.drawOverwrite(34, startY + static_cast<uint8_t>(Shop::mainMenuCurrentRow) * spacing, squareIcon_tiles, 0);
    renderer.drawString(40, startY + spacing * 0, buy_string);
    renderer.drawString(40, startY + spacing * 1, sell_string);
    renderer.drawString(40, startY + spacing * 2, chat_string);
}

void Shop::updateBuy(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON)) {
        Shop::currentUpdate = &Shop::updateMainMenu;
        Shop::currentRender = &Shop::renderMainMenu;
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
        buyMenuCurrentRow = next(buyMenuCurrentRow);
    }

    if (arduboy.justPressed(UP_BUTTON)) {
        buyMenuCurrentRow = prev(buyMenuCurrentRow);
    }
}

const uint8_t BUY_MENU_ITEMS_COUNT = 4;
const uint8_t BUY_MENU_ITEM_PROPS_COUNT = 3;

const uint16_t PROGMEM buyMenuItems[BUY_MENU_ITEMS_COUNT * BUY_MENU_ITEM_PROPS_COUNT] = {
    reinterpret_cast<int16_t>(grub_plus_mask),
    reinterpret_cast<int16_t>(grub_string),
    1,
    reinterpret_cast<int16_t>(shrimp_plus_mask),
    reinterpret_cast<int16_t>(shrimp_string),
    4,
    reinterpret_cast<int16_t>(proPole_plus_mask),
    reinterpret_cast<int16_t>(proPole_string),
    200,
    reinterpret_cast<int16_t>(boatOar_plus_mask),
    reinterpret_cast<int16_t>(boatOars_string),
    200
};

void Shop::renderBuy(uint8_t frame) {
    renderFrame();

    const uint8_t startY = 22;
    const uint8_t startX = 24;
    const uint8_t spacing = 10;

    for (uint8_t i = 0; i < BUY_MENU_ITEMS_COUNT; ++i) {
        const uint8_t y = startY + spacing * i;

        // icon
        const uint8_t* bmp = reinterpret_cast<const uint8_t*>(pgm_read_ptr(buyMenuItems + i * BUY_MENU_ITEM_PROPS_COUNT));
        renderer.drawPlusMask(startX, y, bmp, 0, 0, Invert);

        // name
        const uint8_t* str = reinterpret_cast<const uint8_t*>(pgm_read_ptr(buyMenuItems + i * BUY_MENU_ITEM_PROPS_COUNT + 1));
        renderer.drawString(startX + 21, y + 1, str);

        
        // price
        const int16_t price = static_cast<int16_t>(pgm_read_word(buyMenuItems + i * BUY_MENU_ITEM_PROPS_COUNT + 2));

        if ((i == 2 && State::gameState.hasProPole) || (i == 3 && State::gameState.hasOars)) {
        } else {
            // currency symbol
            renderer.drawPlusMask(startX + 68, y, currencySymbol_plus_mask, 0);
            // then price
            renderer.drawNumber(startX + 74, y + 1, price);
        }
    }

    renderer.drawOverwrite(startX - 7, startY + 2 + spacing * static_cast<int8_t>(buyMenuCurrentRow),  squareIcon_tiles, 0);
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
    renderFrame();

    uint16_t moneyAmount = 0;

    Fish fish;
    for (uint8_t f = 0; f < static_cast<int8_t>(FishType::COUNT); ++f) {
        Fish::loadFish(static_cast<FishType>(f), fish);
        moneyAmount += State::gameState.currentFishCount[f] * fish.value;
    }

    if (moneyAmount == 0) {
        renderer.drawString(24, 30, youHaveNoFish_string);
        renderer.drawString(24, 38, toSellMe_string);
    } else {
        renderer.drawString(20, 30, sellFor_string);

        renderer.drawPlusMask(43, 39, currencySymbol_plus_mask, 0);
        renderer.drawNumber(49, 40, moneyAmount);
        renderer.drawRect(38, 37, 50, 10, WHITE);
    }

    renderer.drawOverwrite(54, 50, squareIcon_tiles, 0);
    renderer.drawString(60, 50, ok_string);
}
