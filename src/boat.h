#pragma once

#include <Arduino.h>

struct Boat {
    static int16_t x;
    static int16_t y;
    static int8_t frame;

    static void render(uint8_t frame);
};

