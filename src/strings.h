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
    // 'B' and 'C'
    0x0,0x64,0x64,0x61,
    // 'D' and 'E'
    0x0,0x46,0x46,0x69,
    // 'F' and 'G'
    0x0,0x6a,0x6a,0x2e,
    // 'H' and 'I'
    0x60,0xb,0x6b,0xf0,
    // 'L' and 'M'
    0x0,0xe7,0xc7,0x7,
    // 'N' and 'O'
    0x0,0x6d,0x6b,0x0,
    // 'R' and 'S'
    0x40,0x4a,0x22,0x28,
    // 'T' and 'U'
    0xe,0x70,0x7e,0xe,
    // 'V' and 'W'
    0x8,0x77,0x37,0x8,
    // 'X' and 'Y'
    0x86,0x39,0xb9,0x86,
};

const uint8_t PROGMEM font_tiles_upper_mask[] = {
    0x0f, 0x0f, 0x0f, 0x0f
};

const uint8_t PROGMEM font_tiles_lower_mask[] = {
    0xf0, 0xf0, 0xf0, 0xf0
};


// "NEW GAME"
const uint8_t newGame_string[9] PROGMEM = {
    22, 15, 29, 0, 17, 11, 21, 15, 0xFF
};


// "CONTINUE"
const uint8_t continue_string[9] PROGMEM = {
    13, 23, 22, 26, 19, 22, 27, 15, 0xFF
};


// "DELETE SAVE"
const uint8_t deleteSave_string[12] PROGMEM = {
    14, 15, 20, 15, 26, 15, 0, 25, 11, 28, 15, 0xFF
};


// "SFX ON"
const uint8_t sfxOn_string[7] PROGMEM = {
    25, 16, 30, 0, 23, 22, 0xFF
};


// "SFX OFF"
const uint8_t sfxOff_string[8] PROGMEM = {
    25, 16, 30, 0, 23, 16, 16, 0xFF
};


// "BUY"
const uint8_t buy_string[4] PROGMEM = {
    12, 27, 31, 0xFF
};


// "SELL"
const uint8_t sell_string[5] PROGMEM = {
    25, 15, 20, 20, 0xFF
};


// "BUY STUFF HERE"
const uint8_t tempBuy_string[15] PROGMEM = {
    12, 27, 31, 0, 25, 26, 27, 16, 16, 0, 18, 15, 24, 15, 0xFF
};


// "SELL STUFF HERE"
const uint8_t tempSell_string[16] PROGMEM = {
    25, 15, 20, 20, 0, 25, 26, 27, 16, 16, 0, 18, 15, 24, 15, 0xFF
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
