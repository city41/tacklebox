#pragma once

#include <Arduino.h>

struct Shop {
    typedef void (*UpdatePtr)(uint8_t);
    typedef void (*RenderPtr)(uint8_t);

    static UpdatePtr currentUpdate;
    static RenderPtr currentRender;

    static void onEnter();

    static void update(uint8_t frame);
    static void render(uint8_t frame);

    static uint8_t mainMenuCurrentRow;
    static void updateMainMenu(uint8_t frame);
    static void renderMainMenu(uint8_t frame);

    static void updateBuy(uint8_t frame);
    static void renderBuy(uint8_t frame);

    static void updateSell(uint8_t frame);
    static void renderSell(uint8_t frame);
};


