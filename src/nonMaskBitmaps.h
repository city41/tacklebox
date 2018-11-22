#ifndef nonMaskBitmaps_h
#define nonMaskBitmaps_h

const uint8_t PROGMEM bobber_tiles[] = {
    // width, height,
    8, 8,
    // frame 0
    0xf7,0xe1,0xc2,0xc6,0xc6,0xc2,0xe1,0xf7,
    // frame 1
    0xf7,0xe3,0xe5,0xe5,0xe5,0xe5,0xe3,0xf7,
};

const uint8_t PROGMEM city41Logo_tiles[] = {
    // width, height,
    16, 8,
    // frame 0
    0xff,0xd5,0xab,0xd5,0xff,0x00,0x1f,0x1f,0x18,0x18,0xff,0xff,0x00,0x03,0xff,0xff,
};

const uint8_t PROGMEM cursor_tiles[] = {
    // width, height,
    8, 8,
    // frame 0
    0x7e,0xe7,0xe7,0x81,0x81,0xe7,0xe7,0x7e,
};

const uint8_t PROGMEM logo_tiles[] = {
    // width, height,
    88, 32,
    // frame 0
    0x00,0x00,0x00,0x1c,0xe2,0x02,0x02,0x02,0x02,0x3c,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xc4,0x04,0x04,0x04,0x18,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x01,0x01,0x01,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x10,0x10,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xa0,0x20,0x20,0xa0,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x90,0x08,0x08,0x08,0x07,0x00,0x00,0x00,0x00,0x03,0x04,0x04,0x82,0x42,0x22,0x3c,0x20,0x20,0x20,0x20,0x20,0x40,0x80,0x00,0x80,0x40,0x41,0x46,0x78,0x40,0x80,0x00,0x0f,0x30,0x10,0x08,0x84,0x42,0x23,0xf2,0x0c,0x00,0xff,0x00,0x80,0x80,0x80,0x40,0x40,0x40,0x80,0xff,0x00,0x00,0x7f,0x80,0x80,0x60,0x10,0x0c,0x04,0x02,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x01,0x01,0x02,0x04,0x0c,0x1a,0x62,0x82,0x04,0x78,0x20,0x10,0x08,0x84,0x44,0x38,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x0e,0xf0,0x00,0x00,0x00,0x7f,0xc0,0x00,0x00,0x1c,0x22,0x22,0x1e,0x00,0x80,0x3c,0xc2,0x01,0x00,0x1c,0x22,0x42,0x42,0x7e,0x82,0x01,0xc0,0x20,0x42,0x85,0x08,0x30,0x40,0xff,0x00,0x00,0x7f,0x81,0x00,0x18,0x2a,0x4a,0x4a,0x48,0x44,0xff,0x00,0x00,0x38,0x48,0x3f,0xfe,0xfc,0xfc,0xf8,0xf8,0xf8,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf8,0xf8,0xf8,0xfc,0xfc,0xfe,0x3f,0xc0,0x00,0x04,0x9a,0x61,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x7e,0x80,0x80,0x80,0x71,0x0e,0x04,0x04,0x04,0x04,0x02,0x01,0x00,0x01,0x02,0x03,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x03,0x00,0x00,0x00,0x00,0x03,0x04,0x04,0x1f,0x20,0x20,0x20,0x1f,0x01,0x02,0x02,0x02,0x02,0x02,0x01,0x03,0x06,0x04,0x04,0x02,0x02,0x01,0x01,0x03,0x0b,0x0b,0x2b,0x33,0xb7,0xb7,0xf7,0xf7,0x77,0x57,0x87,0x93,0x13,0x3b,0x3b,0x2b,0x09,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
};

const uint8_t PROGMEM map_tiles[] = {
    // width, height,
    16, 16,
    // frame 0
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    // frame 1
    0xff,0xff,0xfb,0xf7,0xff,0xff,0xff,0xff,0xff,0xbf,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xf7,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xff,0xff,
    // frame 2
    0xff,0xff,0xef,0x9f,0x5f,0x6f,0xaf,0x77,0xf7,0xf7,0xef,0xd7,0xbf,0x4f,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xfe,0xfd,0xfd,0xfd,0xfd,0xfe,0xff,0xff,0xff,
    // frame 3
    0xff,0x01,0x00,0x00,0x38,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x38,0x00,0x00,0x01,0xff,0xbf,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x8c,0x8c,0x80,0x80,0xbf,
    // frame 4
    0xff,0xf7,0xbd,0xff,0xff,0xf6,0x5f,0xff,0xff,0x6f,0xfd,0xff,0xbf,0xff,0xfe,0xf7,0xfe,0xff,0xbb,0xff,0xff,0xf7,0xbf,0xff,0xfb,0xff,0xdf,0xf7,0x7f,0xff,0xdf,0xfb,
    // frame 5
    0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xb7,0xab,0xcd,0xf5,0x5e,0xf5,0xdf,0xfe,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xd6,0xda,0xba,0xbd,0x6f,0xfd,0xb7,0xfe,0x6f,
    // frame 6
    0xfa,0xaf,0xfd,0x83,0x7d,0xfe,0xff,0x87,0xfd,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0x7e,0xdb,0x7e,0xf7,0x1f,0xee,0xf1,0x7f,0xde,0xf7,0xff,0xff,0xff,0xff,0xfe,0xff,
    // frame 7
    0xff,0xff,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xe6,0xe1,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,
    // frame 8
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xe1,0xe6,0xf8,0xff,0xff,
    // frame 9
    0xff,0xff,0x1f,0xe7,0xf7,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xff,0xff,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    // frame 10
    0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xf7,0xe7,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xff,
    // frame 11
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xff,
    // frame 12
    0xff,0xff,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    // frame 13
    0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    // frame 14
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,
    // frame 15
    0x01,0xfd,0xf5,0xfd,0xfd,0x01,0xfd,0xf5,0xfd,0xfd,0x01,0xfd,0xf5,0xfd,0xfd,0x01,0xc0,0xdf,0x9f,0x97,0xdf,0xc0,0xdf,0x9f,0x97,0xdf,0xc0,0xdf,0x9f,0x97,0xdf,0xc0,
    // frame 16
    0xff,0xff,0x00,0xff,0xff,0xff,0xf7,0xfb,0xf7,0xff,0xff,0xff,0xfb,0xfd,0xfb,0xff,0xff,0xff,0xf8,0xe7,0xef,0xdf,0xdf,0xdf,0xdf,0xdf,0xdf,0xdd,0xde,0xdd,0xdf,0xdf,
    // frame 17
    0xff,0xfb,0xfd,0xfb,0xff,0xff,0xff,0xf7,0xfb,0xf7,0xff,0xff,0xff,0x00,0xff,0xff,0xdf,0xdf,0xdd,0xde,0xdd,0xdf,0xdf,0xdf,0xdf,0xdf,0xdf,0xef,0xe7,0xf8,0xff,0xff,
    // frame 18
    0xff,0xff,0x1f,0xe7,0x07,0xbb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0x5b,0xc3,0xdb,0xff,0xff,0x00,0xfe,0xff,0xff,0xef,0xf7,0xef,0xff,0xff,0xff,0xfe,0xff,0xfe,0xff,
    // frame 19
    0xdb,0xc3,0x5b,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xbb,0x07,0xe7,0x1f,0xff,0xff,0xff,0xfe,0xff,0xfe,0xff,0xff,0xff,0xef,0xf7,0xef,0xff,0xff,0xfe,0x00,0xff,0xff,
    // frame 20
    0xff,0xff,0xdf,0xef,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xfb,0xf7,0xff,0xff,0xff,0xff,0xbf,0xdf,0xbf,0xff,0xff,0xff,0xff,0xf7,0xfb,0xf7,0xff,0xff,0xff,0xff,
    // frame 21
    0x00,0x00,0x20,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x04,0x08,0x00,0x00,0x00,0x00,0x40,0x20,0x40,0x00,0x00,0x00,0x00,0x08,0x04,0x08,0x00,0x00,0x00,0x00,
    // frame 22
    0xff,0xff,0x7f,0xbf,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xfb,0xf7,0xff,0xff,0xdf,0xdf,0xdf,0xdf,0xdf,0xdf,0xdf,0xdf,0xdf,0xdb,0xdd,0xdb,0xdf,0xdf,0xdf,0xdf,
    // frame 23
    0xdb,0xc3,0x5b,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xdb,0xc3,0xff,0xfe,0xff,0xfe,0xff,0xff,0xff,0xef,0xf7,0xef,0xff,0xff,0xff,0xff,0xff,0xff,
    // frame 24
    0xff,0xff,0x00,0xff,0xff,0xf7,0xfb,0xf7,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0xef,0xf7,0xef,0xff,0xff,0xff,0xfe,0xff,0xfe,0xff,
    // frame 25
    0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xf7,0xfb,0xf7,0xff,0xff,0x00,0xff,0xff,0xff,0xfe,0xff,0xfe,0xff,0xff,0xff,0xef,0xf7,0xef,0xff,0xff,0xff,0x00,0xff,0xff,
    // frame 26
    0xff,0xff,0xff,0xff,0xff,0xff,0xbf,0xdf,0xbf,0xff,0xff,0xff,0xff,0xfb,0xfd,0xfb,0xff,0xef,0xf7,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xfd,0xfb,0x3f,0xdf,0xdf,
    // frame 27
    0xff,0xff,0xff,0x7f,0xbf,0xcd,0xf7,0xff,0xff,0xff,0xff,0xff,0x3f,0xcf,0xf7,0xff,0xff,0xff,0xff,0xfe,0xff,0xf7,0xef,0xff,0xbf,0xdf,0xff,0xff,0xfc,0xf3,0xff,0xff,
    // frame 28
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x7f,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x98,0xfc,
    // frame 29
    0xff,0x7f,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x98,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    // frame 30
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xc0,0xe0,0xc0,0xc0,0xc0,0xc0,0x80,0x00,0x00,0x80,0xf0,0xc0,0x80,0x80,0xc0,
    // frame 31
    0x03,0x03,0x07,0x03,0x03,0x03,0x03,0x01,0x00,0x00,0x01,0x0f,0x03,0x01,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    // frame 32
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    // frame 33
    0x03,0x03,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    // frame 34
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xe0,0xc0,0xc0,
    // frame 35
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xc0,0xe0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    // frame 36
    0xff,0xff,0xff,0xff,0xff,0xff,0xbf,0x5f,0xdf,0xdf,0xe7,0xfb,0xfd,0xfd,0xfd,0xfd,0xff,0xff,0xff,0xff,0xff,0xf7,0xeb,0xdc,0xdf,0xdf,0xbf,0xbf,0xb7,0xaf,0xdf,0xbf,
    // frame 37
    0xfd,0xfd,0xfd,0xfd,0xfb,0xe7,0xdf,0xdf,0x5f,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xbf,0xdf,0xaf,0xb7,0xbf,0xbf,0xdf,0xdf,0xdc,0xeb,0xf7,0xff,0xff,0xff,0xff,0xff,
    // frame 38
    0xff,0x00,0xff,0xff,0x00,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0x00,0xff,0x80,0xbf,0xbf,0x80,0xb6,0xb6,0xb6,0x96,0x96,0x96,0xb6,0xb2,0xb6,0xb6,0x80,
    // frame 39
    0x00,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0x5b,0x5b,0xdb,0xdb,0x00,0xff,0xff,0x00,0xff,0x80,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0x96,0x80,0xbf,0xbf,0x80,0xff,
    // frame 40
    0x00,0x00,0xfc,0xf4,0xfc,0xdc,0x9c,0xbc,0xbc,0xdc,0xdc,0xdc,0x1c,0xdc,0xbc,0x7c,0x80,0x00,0x9f,0x97,0x1f,0x9d,0x9c,0x9e,0x9e,0x9d,0x9d,0x9d,0x9d,0x9d,0x9e,0x1f,
    // frame 41
    0xfc,0xfc,0x9c,0x6c,0x6c,0x6c,0xdc,0xfc,0x0c,0x7c,0x7c,0x7c,0x0c,0xfc,0x1c,0xec,0x1f,0x9f,0x99,0x93,0x93,0x93,0x98,0x9f,0x90,0x9e,0x9e,0x9e,0x90,0x9f,0x98,0x13,
    // frame 42
    0xec,0xec,0xec,0x1c,0xfc,0x0c,0x6c,0x6c,0x6c,0x1c,0xfc,0xfc,0xf4,0xfc,0x00,0x00,0x13,0x93,0x93,0x98,0x9f,0x90,0x9e,0x9e,0x9e,0x9f,0x9f,0x1f,0x97,0x9f,0x00,0x80,
};

const uint8_t PROGMEM shopOwner_tiles[] = {
    // width, height,
    17, 24,
    // frame 0
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    // frame 1
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x98,0x78,0x78,0x7c,0x6c,0xbc,0x3c,0xbc,0x6c,0xfc,0x78,0xf8,0x98,0x80,0x80,0x07,0x07,0x02,0x01,0x03,0x01,0x03,0x00,0x01,0x02,0x01,0x02,0x01,0x02,0x01,0x03,0x03,
    // frame 2
    0x00,0x00,0x60,0xe0,0xe0,0xf0,0xb0,0xf0,0xf0,0xf0,0xb0,0xf0,0xe0,0xe0,0x60,0x00,0x00,0xe0,0xf0,0xf8,0x7f,0x7f,0x7f,0x7f,0xfe,0x98,0x5e,0x9f,0x4f,0xbf,0x7f,0xf8,0x70,0xe0,0x07,0x07,0x06,0x03,0x07,0x03,0x07,0x00,0x03,0x01,0x02,0x01,0x02,0x01,0x02,0x01,0x03,
    // frame 3
    0x00,0x00,0x0c,0xfc,0xfc,0xfe,0xf6,0xde,0x1e,0xde,0xf6,0xfe,0xfc,0xfc,0x0c,0x00,0x00,0xf0,0xf8,0xfe,0x7f,0x7f,0x7d,0x7b,0xf3,0xeb,0xd3,0xeb,0xd5,0xeb,0xf7,0xfe,0x78,0xf0,0x07,0x07,0x06,0x03,0x07,0x03,0x07,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x02,0x03,0x03,
};

const uint8_t PROGMEM squareIcon_tiles[] = {
    // width, height,
    3, 8,
    // frame 0
    0x07,0x07,0x07,
};

#endif