#pragma once

#include <Arduino.h>

enum class Dock {
    Beach,
    Island,
    COUNT
};

struct Boat {
    static int16_t x;
    static int16_t y;
    static int8_t frame;
    static bool arrived;
    static bool traveling;
    static Dock currentDock;

    static void onEnter();
    static void update(uint8_t frame);
    static void render(uint8_t frame);
};

