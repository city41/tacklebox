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
    // 'K' and 'L'
    0x0,0x7d,0x7a,0x76,
    // 'M' and 'N'
    0x0,0xde,0xbc,0x0,
    // 'O' and 'R'
    0x0,0xa6,0x26,0x80,
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
    23, 15, 30, 0, 17, 11, 22, 15, 0xFF
};


// "CONTINUE"
const uint8_t continue_string[9] PROGMEM = {
    13, 24, 23, 27, 19, 23, 28, 15, 0xFF
};


// "DELETE SAVE"
const uint8_t deleteSave_string[12] PROGMEM = {
    14, 15, 21, 15, 27, 15, 0, 26, 11, 29, 15, 0xFF
};


// "SFX ON"
const uint8_t sfxOn_string[7] PROGMEM = {
    26, 16, 31, 0, 24, 23, 0xFF
};


// "SFX OFF"
const uint8_t sfxOff_string[8] PROGMEM = {
    26, 16, 31, 0, 24, 16, 16, 0xFF
};


// "BUY"
const uint8_t buy_string[4] PROGMEM = {
    12, 28, 32, 0xFF
};


// "SELL"
const uint8_t sell_string[5] PROGMEM = {
    26, 15, 21, 21, 0xFF
};


// "BUY STUFF HERE"
const uint8_t tempBuy_string[15] PROGMEM = {
    12, 28, 32, 0, 26, 27, 28, 16, 16, 0, 18, 15, 25, 15, 0xFF
};


// "SELL STUFF HERE"
const uint8_t tempSell_string[16] PROGMEM = {
    26, 15, 21, 21, 0, 26, 27, 28, 16, 16, 0, 18, 15, 25, 15, 0xFF
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


// "GOLDFISH"
const uint8_t goldfish_string[9] PROGMEM = {
    17, 24, 21, 14, 16, 19, 26, 18, 0xFF
};


// "SHARK"
const uint8_t shark_string[6] PROGMEM = {
    26, 18, 11, 25, 20, 0xFF
};


// "SAVE"
const uint8_t save_string[5] PROGMEM = {
    26, 11, 29, 15, 0xFF
};

#endif
