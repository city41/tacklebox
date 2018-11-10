#pragma once


#include "maskBitmaps.h"

const uint8_t NUM_U8T_PROPS = 8;
const uint8_t NUM_16T_PROPS = 3;


const uint8_t PROGMEM fish_templates_u8t[] = {

    // GOLDFISH
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    1,  // baitPreference SHRIMP
    1,  // baitPreference MEAT
    10,  // ratio
    1,  // value

    // SHARK
    5,  // minHour
    19,  // maxHour
    1,  // baitPreference WORM
    0,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    1,  // baitPreference MEAT
    10,  // ratio
    100,  // value
};


const uint8_t GOLDFISH_string[9] PROGMEM = {
    17, 25, 22, 14, 16, 19, 29, 18, 0xFF
};

const uint8_t SHARK_string[6] PROGMEM = {
    29, 18, 11, 28, 21, 0xFF
};

const uint8_t* const PROGMEM allFishNameStrings[] = {
    GOLDFISH_string,
    SHARK_string
};

const int16_t PROGMEM fish_templates_16t[] = {

    // GOLDFISH
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(GOLDFISH_string),
    reinterpret_cast<int16_t>(GOLDFISH_plus_mask),

    // SHARK
    640, // min X
    736, // max X
    reinterpret_cast<int16_t>(SHARK_string),
    reinterpret_cast<int16_t>(SHARK_plus_mask),
};
