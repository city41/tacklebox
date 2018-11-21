#pragma once

#include <Arduino.h>
#include "fishType.h"
#include "baitType.h"

struct Fish {
    FishType type;
    uint8_t minHour;
    uint8_t maxHour;
    int16_t minX;
    int16_t maxX;
    uint8_t baitPreferences[static_cast<uint8_t>(BaitType::NUM_BAITS)];
    uint8_t ratio;
    uint8_t value;
    
    const uint8_t* nameString;
    const uint8_t* bmp;

    uint8_t nameLength;
    uint8_t bmpWidth;

    static void loadFish(FishType fishType, Fish& fish);
};

