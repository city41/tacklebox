#pragma once

const uint8_t NUM_U8T_PROPS = 8;
const uint8_t NUM_16T_PROPS = 2;

const uint8_t PROGMEM fish_templates_u8t[] = {
    // GOLDFISH
    0,    // minHour
    23,   // maxHour
    1,    // baitPreference WORM
    1,    // baitPreference GRUB
    1,    // baitPreference SHRIMP
    1,    // baitPreference MEAT
    10,   // ratio
    1,    // value

    // SHARK
    0,    // minHour
    23,   // maxHour
    0,    // baitPreference WORM
    0,    // baitPreference GRUB
    0,    // baitPreference SHRIMP
    1,    // baitPreference MEAT
    1,   // ratio
    100,    // value
};

const int16_t PROGMEM fish_templates_16t[] = {
    // GOLDFISH
    0,     // minX
    30000, // maxX

    // SHARK
    0,     // minX
    30000, // maxX
};

