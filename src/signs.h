#pragma once
#include "sign.h"

const int8_t MAX_SIGNS = 3;

Sign signs[MAX_SIGNS] = {
    // sign at start of game with URL to manual
    Sign(16 * 26, 16 * 16, signGameManual_string),
    // on island, hinting sharks can be found
    Sign(16 * 41, 12 * 16 - 4, signSharkWarning_string),
    // on the beach, letting player know worms wont work in the ocean
    Sign(16 * 33 - 10, 16 * 4, signOceanFish_string)
};
