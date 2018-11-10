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
