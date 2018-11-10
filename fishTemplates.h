#pragma once

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
    0,  // baitPreference WORM
    0,  // baitPreference GRUB
    0,  // baitPreference SHRIMP
    1,  // baitPreference MEAT
    1,  // ratio
    100,  // value
};


const uint8_t GOLDFISH_string[9] PROGMEM = {
    17, 25, 22, 14, 16, 19, 29, 18
};

const uint8_t SHARK_string[6] PROGMEM = {
    29, 18, 11, 28, 21
};

const int16_t PROGMEM fish_templates_16t[] = {

    // GOLDFISH
    368, // min X
    432, // max X
    GOLDFISH_string

    // SHARK
    640, // min X
    736, // max X
    SHARK_string
};
