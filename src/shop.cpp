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
#include "sfx.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

ShopMainMenu Shop::mainMenuCurrentRow = ShopMainMenu::Buy;
BuyMenu Shop::buyMenuCurrentRow = BuyMenu::Grub;
Shop::UpdatePtr Shop::currentUpdate = &Shop::updateMainMenu;
Shop::RenderPtr Shop::currentRender = &Shop::renderMainMenu;
bool Shop::showAdvice = false;


const uint8_t PROGMEM shopOwnerDurations[] = {
    20, 0, 5, 1, 5, 2, 5, 3, 255
};

const uint16_t GRUB_PRICE = 1;
const uint16_t SHRIMP_PRICE = 3;
const uint16_t PRO_POLE_PRICE = 200;
const uint16_t OARS_PRICE = 400;

const uint8_t BUY_MENU_ITEMS_COUNT = 4;
const uint8_t BUY_MENU_ITEM_PROPS_COUNT = 3;

const uint16_t PROGMEM buyMenuItems[BUY_MENU_ITEMS_COUNT * BUY_MENU_ITEM_PROPS_COUNT] = {
    reinterpret_cast<int16_t>(grub_plus_mask),
    reinterpret_cast<int16_t>(grub_string),
    GRUB_PRICE,
    reinterpret_cast<int16_t>(shrimp_plus_mask),
    reinterpret_cast<int16_t>(shrimp_string),
    SHRIMP_PRICE,
    reinterpret_cast<int16_t>(proPole_plus_mask),
    reinterpret_cast<int16_t>(proPole_string),
    PRO_POLE_PRICE,
    reinterpret_cast<int16_t>(boatOar_plus_mask),
    reinterpret_cast<int16_t>(boatOars_string),
    OARS_PRICE
};

const uint8_t* const PROGMEM adviceStrings[] = {
    NULL,
    advice1_string,
    advice2_string,
    advice3_string,
    advice4_string,
    advice5_string,
    advice6_string,
    advice7_string,
    advice8_string
};

Animation shopOwnerAnimation(shopOwnerDurations);

bool Shop::isOpen() {
    const uint8_t hour = State::getCurrentHour();

    return hour >= 4 && hour <= 21;
}

void Shop::onEnter() {
    shopOwnerAnimation.reset();
}

void Shop::update(uint8_t frame) {
    Shop::currentUpdate(frame);
}

void Shop::render(uint8_t frame) {
    Shop::currentRender(frame);

    // user's current money in upper corner
    renderer.drawPlusMask(WIDTH - 42, 0, currencySymbol_plus_mask, 0);
    renderer.drawNumber(WIDTH - 36, 1, State::gameState.money);

    // user's current grub and shrimp count for reference
    renderer.drawPlusMask(WIDTH - 70, 8, grub_plus_mask, 0, 0, Invert);
    renderer.drawNumber(WIDTH - 58, 10, State::gameState.baitCounts[static_cast<int8_t>(BaitType::Grub)]);

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
        if (mainMenuCurrentRow == ShopMainMenu::Buy) {
            currentUpdate = &Shop::updateBuy;
            currentRender = &Shop::renderBuy;
        } else if (mainMenuCurrentRow == ShopMainMenu::Sell) {
            currentUpdate = &Shop::updateSell;
            currentRender = &Shop::renderSell;
        } else if (mainMenuCurrentRow == ShopMainMenu::Advice) {
            showAdvice = false;
            currentUpdate = &Shop::updateAdvice;
            currentRender = &Shop::renderAdvice;
        } else {
            currentUpdate = &Shop::updateHours;
            currentRender = &Shop::renderHours;
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

    const uint8_t startY = 25;
    const uint8_t x = 48;
    const uint8_t spacing = 9;

    renderer.drawOverwrite(x - 6, startY + static_cast<uint8_t>(Shop::mainMenuCurrentRow) * spacing, squareIcon_tiles, 0);
    renderer.drawString(x, startY + spacing * 0, buy_string);
    renderer.drawString(x, startY + spacing * 1, sell_string);
    renderer.drawString(x, startY + spacing * 2, advice_string);
    renderer.drawString(x, startY + spacing * 3, hours_string);
}

void buy(BuyMenu itemToBuy) {
    bool buzz = false;

    switch (itemToBuy) {
        case BuyMenu::Grub:
            if (State::gameState.money >= GRUB_PRICE) {
                State::gameState.money -= GRUB_PRICE;
                State::gameState.baitCounts[static_cast<int8_t>(BaitType::Grub)] += 1;
            } else {
                buzz = true;
            }
            break;
        case BuyMenu::Shrimp:
            if (State::gameState.money >= SHRIMP_PRICE) {
                State::gameState.money -= SHRIMP_PRICE;
                State::gameState.baitCounts[static_cast<int8_t>(BaitType::Shrimp)] += 1;
            } else {
                buzz = true;
            }
            break;
        case BuyMenu::ProPole:
            if (State::gameState.money >= PRO_POLE_PRICE && !State::gameState.hasProPole) {
                State::gameState.money -= PRO_POLE_PRICE;
                State::gameState.hasProPole = true;
            } else {
                buzz = true;
            }
            break;
        case BuyMenu::Oars:
            if (State::gameState.money >= OARS_PRICE && !State::gameState.hasOars) {
                State::gameState.money -= OARS_PRICE;
                State::gameState.hasOars = true;
            } else {
                buzz = true;
            }
            break;
    }

    if (buzz) {
        Sfx::play(Sfx::buzz);
    }
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

    if (arduboy.justPressed(A_BUTTON)) {
        buy(buyMenuCurrentRow);
    }
}



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

void Shop::updateAdvice(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON)) {
        Shop::currentUpdate = &Shop::updateMainMenu;
        Shop::currentRender = &Shop::renderMainMenu;
    }

    if (!showAdvice && arduboy.justPressed(A_BUTTON)) {
        if (
            State::gameState.adviceLevel < 8 &&
            State::gameState.money >= (1 << State::gameState.adviceLevel)
        ) {
            State::gameState.money -= (1 << State::gameState.adviceLevel);

            State::gameState.adviceLevel += 1;
            showAdvice = true;
        } else {
            Sfx::play(Sfx::buzz);
        }
    }
}

void Shop::renderAdvice(uint8_t frame) {
    renderFrame();

    if (State::gameState.adviceLevel == 8 && !showAdvice) {
        renderer.drawString(20, 30, noMoreAdvice_string);
    } else if (showAdvice) {
        const uint8_t* str = static_cast<const uint8_t*>(pgm_read_ptr(adviceStrings + State::gameState.adviceLevel));
        renderer.drawString(20, 30, str);
    } else {
        uint16_t moneyAmount = (1 << State::gameState.adviceLevel);

        renderer.drawString(20, 30, adviceFor_string);

        renderer.drawPlusMask(43, 39, currencySymbol_plus_mask, 0);
        renderer.drawNumber(49, 40, moneyAmount);
        renderer.drawRect(38, 37, 50, 10, WHITE);

        renderer.drawOverwrite(54, 50, squareIcon_tiles, 0);
        renderer.drawString(60, 50, ok_string);
    }
}

void Shop::updateHours(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON)) {
        Shop::currentUpdate = &Shop::updateMainMenu;
        Shop::currentRender = &Shop::renderMainMenu;
    }
}

void Shop::renderHours(uint8_t frame) {
    renderFrame();

    renderer.drawString(25, 36, openFromTo_string);
}
