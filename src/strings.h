#ifndef strings_h
#define strings_h

const uint8_t PROGMEM font_tiles[] =  {
    // width, height
    4, 8,
    // ' ' and '0'
    0xf,0x6f,0x4f,0xf,
    // '1' and '2'
    0x2f,0x26,0x40,0x47,
    // '3' and '4'
    0x86,0xb4,0xb4,0x0,
    // '5' and '6'
    0x8,0x52,0x52,0x12,
    // '7' and '8'
    0xe,0x2e,0x2e,0x0,
    // '9' and 'A'
    0x8,0xaa,0xaa,0x0,
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
    20, 14, 26, 0, 16, 11, 19, 14, 0xFF
};


// "CONTINUE"
const uint8_t continue_string[9] PROGMEM = {
    12, 21, 20, 23, 17, 20, 24, 14, 0xFF
};


// "DELETE SAVE"
const uint8_t deleteSave_string[12] PROGMEM = {
    13, 14, 18, 14, 23, 14, 0, 22, 11, 25, 14, 0xFF
};


// "SFX!"
const uint8_t sfxOn_string[5] PROGMEM = {
    22, 15, 27, 28, 0xFF
};


// "SFX"
const uint8_t sfxOff_string[4] PROGMEM = {
    22, 15, 27, 0xFF
};


// "0"
const uint8_t digit0_string[2] PROGMEM = {
    1, 0xFF
};


// "1"
const uint8_t digit1_string[2] PROGMEM = {
    2, 0xFF
};


// "2"
const uint8_t digit2_string[2] PROGMEM = {
    3, 0xFF
};


// "3"
const uint8_t digit3_string[2] PROGMEM = {
    4, 0xFF
};


// "4"
const uint8_t digit4_string[2] PROGMEM = {
    5, 0xFF
};


// "5"
const uint8_t digit5_string[2] PROGMEM = {
    6, 0xFF
};


// "6"
const uint8_t digit6_string[2] PROGMEM = {
    7, 0xFF
};


// "7"
const uint8_t digit7_string[2] PROGMEM = {
    8, 0xFF
};


// "8"
const uint8_t digit8_string[2] PROGMEM = {
    9, 0xFF
};


// "9"
const uint8_t digit9_string[2] PROGMEM = {
    10, 0xFF
};

#endif
