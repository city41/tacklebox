#pragma once

#include <Arduino.h>
#include "fishType.h"
#include "baitType.h"

struct Fish {
    uint8_t minHour;
    uint8_t maxHour;
    int16_t minX;
    int16_t maxX;
    uint8_t baitPreferences[static_cast<uint8_t>(BaitType::NUM_BAITS)];
    uint8_t ratio;
    uint8_t value;

    static void loadFish(FishType fishType, Fish& fish);
};

