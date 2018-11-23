#pragma once


#include "maskBitmaps.h"

const uint8_t NUM_U8T_PROPS = 10;
const uint8_t NUM_16T_PROPS = 4;


const uint8_t PROGMEM fish_templates_u8t[] = {

    // GOLDFISH
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    8, // nameLength
    8, // bmpWidth

    // GUPPY
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    5, // nameLength
    8, // bmpWidth

    // EEL
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    3, // nameLength
    16, // bmpWidth

    // LOBSTER
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    7, // nameLength
    8, // bmpWidth

    // SHARK
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    0,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    1,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    5, // nameLength
    24, // bmpWidth
};


const uint8_t GOLDFISH_string[9] PROGMEM = {
    17, 25, 22, 14, 16, 19, 29, 18, 0xFF
};

const uint8_t GUPPY_string[6] PROGMEM = {
    17, 31, 26, 26, 35, 0xFF
};

const uint8_t EEL_string[4] PROGMEM = {
    15, 15, 22, 0xFF
};

const uint8_t LOBSTER_string[8] PROGMEM = {
    22, 25, 12, 29, 30, 15, 28, 0xFF
};

const uint8_t SHARK_string[6] PROGMEM = {
    29, 18, 11, 28, 21, 0xFF
};

const int16_t PROGMEM fish_templates_16t[] = {

    // GOLDFISH
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(GOLDFISH_string),
    reinterpret_cast<int16_t>(GOLDFISH_plus_mask),

    // GUPPY
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(GUPPY_string),
    reinterpret_cast<int16_t>(GUPPY_plus_mask),

    // EEL
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(EEL_string),
    reinterpret_cast<int16_t>(EEL_plus_mask),

    // LOBSTER
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(LOBSTER_string),
    reinterpret_cast<int16_t>(LOBSTER_plus_mask),

    // SHARK
    368, // min X
    736, // max X
    reinterpret_cast<int16_t>(SHARK_string),
    reinterpret_cast<int16_t>(SHARK_plus_mask),
};
