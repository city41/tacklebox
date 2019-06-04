#pragma once


#include "nonMaskBitmaps.h"

const uint8_t NUM_U8T_PROPS = 13;
const uint8_t NUM_16T_PROPS = 6;


const uint8_t PROGMEM fish_templates_u8t[] = {

    // GOLDFISH
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    5,  // ratio
    2,  // value
    8, // nameLength
    8, // bmpWidth
    3, // pull
    0, // deepWater
    54, // proWindow

    // GUPPY
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    0,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    5,  // ratio
    1,  // value
    5, // nameLength
    8, // bmpWidth
    2, // pull
    0, // deepWater
    80, // proWindow

    // BETA
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    0,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    3,  // ratio
    30,  // value
    4, // nameLength
    8, // bmpWidth
    4, // pull
    0, // deepWater
    80, // proWindow

    // TROUT
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    1,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    3,  // ratio
    14,  // value
    5, // nameLength
    10, // bmpWidth
    5, // pull
    0, // deepWater
    54, // proWindow

    // CRAWFISH
    0,  // minHour
    9,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    4,  // ratio
    20,  // value
    8, // nameLength
    8, // bmpWidth
    6, // pull
    0, // deepWater
    66, // proWindow

    // OLD BOOT
    30,  // minHour
    30,  // maxHour
    0,  // baitPreference WORM
    0,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    0,  // ratio
    0,  // value
    8, // nameLength
    6, // bmpWidth
    3, // pull
    0, // deepWater
    64, // proWindow

    // LOBSTER
    0,  // minHour
    23,  // maxHour
    0,  // baitPreference WORM
    0,  // baitPreference GRUB
    1,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    4,  // ratio
    80,  // value
    7, // nameLength
    11, // bmpWidth
    5, // pull
    0, // deepWater
    80, // proWindow
};


const uint8_t GOLDFISH_string[9] PROGMEM = {
    17, 25, 22, 14, 16, 19, 29, 18, 0xFF
};

const uint8_t GUPPY_string[6] PROGMEM = {
    17, 31, 26, 26, 35, 0xFF
};

const uint8_t BETA_string[5] PROGMEM = {
    12, 15, 30, 11, 0xFF
};

const uint8_t TROUT_string[6] PROGMEM = {
    30, 28, 25, 31, 30, 0xFF
};

const uint8_t CRAWFISH_string[9] PROGMEM = {
    13, 28, 11, 33, 16, 19, 29, 18, 0xFF
};

const uint8_t OLD_BOOT_string[9] PROGMEM = {
    25, 22, 14, 0, 12, 25, 25, 30, 0xFF
};

const uint8_t LOBSTER_string[8] PROGMEM = {
    22, 25, 12, 29, 30, 15, 28, 0xFF
};

const int16_t PROGMEM fish_templates_16t[] = {

    // GOLDFISH
    80, // min X
    432, // max X
    reinterpret_cast<int16_t>(GOLDFISH_string),
    reinterpret_cast<int16_t>(GOLDFISH_tiles),
    3, // minLength;
    20, // maxLength

    // GUPPY
    80, // min X
    432, // max X
    reinterpret_cast<int16_t>(GUPPY_string),
    reinterpret_cast<int16_t>(GUPPY_tiles),
    1, // minLength;
    4, // maxLength

    // BETA
    352, // min X
    432, // max X
    reinterpret_cast<int16_t>(BETA_string),
    reinterpret_cast<int16_t>(BETA_tiles),
    2, // minLength;
    4, // maxLength

    // TROUT
    0, // min X
    288, // max X
    reinterpret_cast<int16_t>(TROUT_string),
    reinterpret_cast<int16_t>(TROUT_tiles),
    15, // minLength;
    25, // maxLength

    // CRAWFISH
    0, // min X
    64, // max X
    reinterpret_cast<int16_t>(CRAWFISH_string),
    reinterpret_cast<int16_t>(CRAWFISH_tiles),
    4, // minLength;
    8, // maxLength

    // OLD BOOT
    352, // min X
    432, // max X
    reinterpret_cast<int16_t>(OLD_BOOT_string),
    reinterpret_cast<int16_t>(OLD_BOOT_tiles),
    1, // minLength;
    10, // maxLength

    // LOBSTER
    560, // min X
    800, // max X
    reinterpret_cast<int16_t>(LOBSTER_string),
    reinterpret_cast<int16_t>(LOBSTER_tiles),
    10, // minLength;
    30, // maxLength
};
