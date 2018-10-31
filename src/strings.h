#ifndef strings_h
#define strings_h

const uint8_t PROGMEM font_tiles[] =  {
    // width, height
    4, 8,
    // ' ' and 'A'
    0xf,0xaf,0xaf,0xf,
    // 'C' and 'D'
    0x0,0x66,0x66,0x96,
    // 'E' and 'F'
    0x0,0xa4,0xa4,0xe6,
    // 'G' and 'I'
    0x60,0x6,0x66,0xf2,
    // 'L' and 'M'
    0x0,0xe7,0xc7,0x7,
    // 'N' and 'O'
    0x0,0x6d,0x6b,0x0,
    // 'S' and 'T'
    0xe4,0x4,0xe2,0xe2,
    // 'U' and 'V'
    0x80,0x77,0x77,0x80,
    // 'W' and 'X'
    0x60,0x97,0x93,0x60,
};

const uint8_t PROGMEM font_tiles_upper_mask[] = {
    0x0f, 0x0f, 0x0f, 0x0f
};

const uint8_t PROGMEM font_tiles_lower_mask[] = {
    0xf0, 0xf0, 0xf0, 0xf0
};


// "NEW GAME"
const uint8_t newGame_string[9] PROGMEM = {
    10, 4, 16, 0, 6, 1, 9, 4, 0xFF
};


// "CONTINUE"
const uint8_t continue_string[9] PROGMEM = {
    2, 11, 10, 13, 7, 10, 14, 4, 0xFF
};


// "DELETE SAVE"
const uint8_t deleteSave_string[12] PROGMEM = {
    3, 4, 8, 4, 13, 4, 0, 12, 1, 15, 4, 0xFF
};


// "SFX!"
const uint8_t sfxOn_string[5] PROGMEM = {
    12, 5, 17, 18, 0xFF
};


// "SFX"
const uint8_t sfxOff_string[4] PROGMEM = {
    12, 5, 17, 0xFF
};

#endif
