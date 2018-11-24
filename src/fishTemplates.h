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

    // MINNOW
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    6, // nameLength
    4, // bmpWidth

    // BETA
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    4, // nameLength
    8, // bmpWidth

    // TROUT
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    5, // nameLength
    10, // bmpWidth

    // BASS
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    4, // nameLength
    12, // bmpWidth

    // BLUEGILL
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    8, // nameLength
    12, // bmpWidth

    // CATFISH
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    7, // nameLength
    12, // bmpWidth

    // FLOUNDER
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    8, // nameLength
    12, // bmpWidth

    // CRAB
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    4, // nameLength
    12, // bmpWidth

    // OCTOPUS
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    7, // nameLength
    14, // bmpWidth

    // GROUPER
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    7, // nameLength
    16, // bmpWidth

    // SEAHORSE
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    8, // nameLength
    4, // bmpWidth

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

    // SARDINE
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    7, // nameLength
    5, // bmpWidth

    // CRAWFISH
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

    // FANGTOOTH
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    9, // nameLength
    12, // bmpWidth

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
    11, // bmpWidth

    // MARLIN
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    1,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    6, // nameLength
    20, // bmpWidth

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

    // GRTWHITE
    0,  // minHour
    23,  // maxHour
    1,  // baitPreference WORM
    0,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    1,  // baitPreference MEAT
    10,  // ratio
    255,  // value
    8, // nameLength
    30, // bmpWidth

    // OLDBOOT
    30,  // minHour
    30,  // maxHour
    0,  // baitPreference WORM
    0,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    0,  // baitPreference MEAT
    0,  // ratio
    0,  // value
    7, // nameLength
    6, // bmpWidth
};


const uint8_t GOLDFISH_string[9] PROGMEM = {
    17, 25, 22, 14, 16, 19, 29, 18, 0xFF
};

const uint8_t GUPPY_string[6] PROGMEM = {
    17, 31, 26, 26, 35, 0xFF
};

const uint8_t MINNOW_string[7] PROGMEM = {
    23, 19, 24, 24, 25, 33, 0xFF
};

const uint8_t BETA_string[5] PROGMEM = {
    12, 15, 30, 11, 0xFF
};

const uint8_t TROUT_string[6] PROGMEM = {
    30, 28, 25, 31, 30, 0xFF
};

const uint8_t BASS_string[5] PROGMEM = {
    12, 11, 29, 29, 0xFF
};

const uint8_t BLUEGILL_string[9] PROGMEM = {
    12, 22, 31, 15, 17, 19, 22, 22, 0xFF
};

const uint8_t CATFISH_string[8] PROGMEM = {
    13, 11, 30, 16, 19, 29, 18, 0xFF
};

const uint8_t FLOUNDER_string[9] PROGMEM = {
    16, 22, 25, 31, 24, 14, 15, 28, 0xFF
};

const uint8_t CRAB_string[5] PROGMEM = {
    13, 28, 11, 12, 0xFF
};

const uint8_t OCTOPUS_string[8] PROGMEM = {
    25, 13, 30, 25, 26, 31, 29, 0xFF
};

const uint8_t GROUPER_string[8] PROGMEM = {
    17, 28, 25, 31, 26, 15, 28, 0xFF
};

const uint8_t SEAHORSE_string[9] PROGMEM = {
    29, 15, 11, 18, 25, 28, 29, 15, 0xFF
};

const uint8_t EEL_string[4] PROGMEM = {
    15, 15, 22, 0xFF
};

const uint8_t SARDINE_string[8] PROGMEM = {
    29, 11, 28, 14, 19, 24, 15, 0xFF
};

const uint8_t CRAWFISH_string[9] PROGMEM = {
    13, 28, 11, 33, 16, 19, 29, 18, 0xFF
};

const uint8_t FANGTOOTH_string[10] PROGMEM = {
    16, 11, 24, 17, 30, 25, 25, 30, 18, 0xFF
};

const uint8_t LOBSTER_string[8] PROGMEM = {
    22, 25, 12, 29, 30, 15, 28, 0xFF
};

const uint8_t MARLIN_string[7] PROGMEM = {
    23, 11, 28, 22, 19, 24, 0xFF
};

const uint8_t SHARK_string[6] PROGMEM = {
    29, 18, 11, 28, 21, 0xFF
};

const uint8_t GRTWHITE_string[9] PROGMEM = {
    17, 28, 30, 33, 18, 19, 30, 15, 0xFF
};

const uint8_t OLDBOOT_string[8] PROGMEM = {
    25, 22, 14, 12, 25, 25, 30, 0xFF
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

    // MINNOW
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(MINNOW_string),
    reinterpret_cast<int16_t>(MINNOW_plus_mask),

    // BETA
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(BETA_string),
    reinterpret_cast<int16_t>(BETA_plus_mask),

    // TROUT
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(TROUT_string),
    reinterpret_cast<int16_t>(TROUT_plus_mask),

    // BASS
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(BASS_string),
    reinterpret_cast<int16_t>(BASS_plus_mask),

    // BLUEGILL
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(BLUEGILL_string),
    reinterpret_cast<int16_t>(BLUEGILL_plus_mask),

    // CATFISH
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(CATFISH_string),
    reinterpret_cast<int16_t>(CATFISH_plus_mask),

    // FLOUNDER
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(FLOUNDER_string),
    reinterpret_cast<int16_t>(FLOUNDER_plus_mask),

    // CRAB
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(CRAB_string),
    reinterpret_cast<int16_t>(CRAB_plus_mask),

    // OCTOPUS
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(OCTOPUS_string),
    reinterpret_cast<int16_t>(OCTOPUS_plus_mask),

    // GROUPER
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(GROUPER_string),
    reinterpret_cast<int16_t>(GROUPER_plus_mask),

    // SEAHORSE
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(SEAHORSE_string),
    reinterpret_cast<int16_t>(SEAHORSE_plus_mask),

    // EEL
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(EEL_string),
    reinterpret_cast<int16_t>(EEL_plus_mask),

    // SARDINE
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(SARDINE_string),
    reinterpret_cast<int16_t>(SARDINE_plus_mask),

    // CRAWFISH
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(CRAWFISH_string),
    reinterpret_cast<int16_t>(CRAWFISH_plus_mask),

    // FANGTOOTH
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(FANGTOOTH_string),
    reinterpret_cast<int16_t>(FANGTOOTH_plus_mask),

    // LOBSTER
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(LOBSTER_string),
    reinterpret_cast<int16_t>(LOBSTER_plus_mask),

    // MARLIN
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(MARLIN_string),
    reinterpret_cast<int16_t>(MARLIN_plus_mask),

    // SHARK
    368, // min X
    736, // max X
    reinterpret_cast<int16_t>(SHARK_string),
    reinterpret_cast<int16_t>(SHARK_plus_mask),

    // GRTWHITE
    368, // min X
    736, // max X
    reinterpret_cast<int16_t>(GRTWHITE_string),
    reinterpret_cast<int16_t>(GRTWHITE_plus_mask),

    // OLDBOOT
    368, // min X
    432, // max X
    reinterpret_cast<int16_t>(OLDBOOT_string),
    reinterpret_cast<int16_t>(OLDBOOT_plus_mask),
};
