#include "girlDialog.h"
#include <Arduboy2.h>
#include "renderer.h"
#include "nonMaskBitmaps.h"
#include "maskBitmaps.h"
#include "animation.h"
#include "strings.h"
#include "state.h"
#include "fishType.h"
#include "baitType.h"
#include "sfx.h"

const uint8_t MEAT_PRICE = 10;

extern Renderer renderer;
extern Arduboy2Base arduboy;

/*
 * TODO: a lot of code here is copied and pasted from Shop,
 * factor this down to a common Dialog class that both can use
 */


const uint8_t PROGMEM fishingGirlDurations[] = {
    20, 0, 5, 1, 5, 2, 5, 3, 255
};

Animation fishingGirlDialogAnimation(fishingGirlDurations);

void renderGirlFrame() {
    // white frame
    renderer.fillRect(13, 19, 103, 1, WHITE);
    renderer.fillRect(116, 20, 1, 42, WHITE);
    renderer.fillRect(12, 20, 1, 42, WHITE);
    renderer.fillRect(13, HEIGHT - 2, 103, 1, WHITE);

    renderer.drawOverwrite(20, 2, fishingGirlDialog_tiles, fishingGirlDialogAnimation.currentFrame);
}

void GirlDialog::onEnter() {
    fishingGirlDialogAnimation.reset();
}

void GirlDialog::update() {
    fishingGirlDialogAnimation.update();

    if (
        !State::gameState.canBuyMeat &&
        State::gameState.currentFishCount[static_cast<int8_t>(FishType::LOBSTER)] >= 5 &&
        arduboy.justPressed(A_BUTTON)
    ) {
        State::gameState.currentFishCount[static_cast<int8_t>(FishType::LOBSTER)] -= 5;
        State::gameState.canBuyMeat = true;
    }
    else if (
        State::gameState.canBuyMeat &&
        arduboy.justPressed(A_BUTTON)
    ) {
        if (State::gameState.money >= MEAT_PRICE) {
            State::gameState.money -= MEAT_PRICE;
            State::gameState.baitCounts[static_cast<int8_t>(BaitType::Meat)] += 1;
        } else {
            Sfx::play(Sfx::buzz);
        }
    }
}

void GirlDialog::render() {
    renderGirlFrame();

    const uint8_t* str = girlQuest_string;

    if (
        !State::gameState.canBuyMeat &&
        State::gameState.currentFishCount[static_cast<int8_t>(FishType::LOBSTER)] >= 5
    ) {
        str = girlRequestLobsters_string;
    }

    if (State::gameState.canBuyMeat) {
        str = girlSellMeat_string;
    }

    renderer.drawString(17, 30, str);

    renderer.drawOverwrite(54, 50, squareIcon_tiles, 0);
    renderer.drawString(60, 50, ok_string);

    if (State::gameState.canBuyMeat) {
        renderer.drawPlusMask(43, 39, currencySymbol_plus_mask, 0);
        renderer.drawNumber(49, 40, MEAT_PRICE);
        renderer.drawRect(38, 37, 50, 10, WHITE);

        // user's current money in upper corner
        renderer.drawPlusMask(WIDTH - 42, 0, currencySymbol_plus_mask, 0);
        renderer.drawNumber(WIDTH - 36, 1, State::gameState.money);

        // user's current meat count for reference
        renderer.drawPlusMask(WIDTH - 48, 8, meat_plus_mask, 0, 0, Invert);
        renderer.drawNumber(WIDTH - 36, 10, State::gameState.baitCounts[static_cast<int8_t>(BaitType::Meat)]);
    }
}

