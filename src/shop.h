#pragma once

#include <Arduino.h>

enum class ShopMainMenu: uint8_t {
    Buy,
    Sell,
    Chat,
    COUNT
};

enum class BuyMenu: uint8_t {
    Grub,
    Shrimp,
    ProPole,
    Oars,
    COUNT
};

struct Shop {
    typedef void (*UpdatePtr)(uint8_t);
    typedef void (*RenderPtr)(uint8_t);

    static UpdatePtr currentUpdate;
    static RenderPtr currentRender;

    static void onEnter();

    static void update(uint8_t frame);
    static void render(uint8_t frame);

    static ShopMainMenu mainMenuCurrentRow;
    static BuyMenu buyMenuCurrentRow;
    static void updateMainMenu(uint8_t frame);
    static void renderMainMenu(uint8_t frame);

    static void updateBuy(uint8_t frame);
    static void renderBuy(uint8_t frame);

    static void updateSell(uint8_t frame);
    static void renderSell(uint8_t frame);
};


