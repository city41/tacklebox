#pragma once

#include <Arduino.h>

struct DialogUtils {
    static void reset();
    static void renderFrame(const uint8_t* bmp);
};

