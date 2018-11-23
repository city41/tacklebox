#pragma once


const int16_t TILE_SIZE = 16;
const int16_t MAP_WIDTH_TILES = 48;
const int16_t MAP_HEIGHT_TILES = 24;
const int16_t MAP_WIDTH_PX = MAP_WIDTH_TILES * TILE_SIZE;
const int16_t MAP_HEIGHT_PX = MAP_HEIGHT_TILES * TILE_SIZE;

const uint8_t PROGMEM world_map[MAP_WIDTH_TILES * MAP_HEIGHT_TILES] = {
    0x14, 0x14, 0x14, 0x13, 0x18, 0x23, 0x1e, 0x1e, 0x1e, 0x23, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x21, 0x28, 0x29, 0x2a, 0x22, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x22, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x14, 0x13, 0x13, 0x13, 0x13, 0x18, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x4, 0x4, 0x26, 0x3, 0x27, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x14, 0x15, 0x15, 0x15, 0x15, 0x10, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0, 0x24, 0x25, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x0, 0x4, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x14, 0x20, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x0, 0x4, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x11, 0x16, 0x16, 0x12, 0x0, 0x0, 0x1, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x17, 0x13, 0x13, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x2, 0x11, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x12, 0x0, 0x0, 0x0, 0x0, 0x17, 0x13, 0x19, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x18, 0x0, 0x0, 0x0, 0x0, 0xf, 0x15, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x13, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x8, 0xc, 0x9, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x1, 0x0, 0x0, 0x0, 0x17, 0x13, 0x8, 0xc, 0xc, 0x9, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x13, 0x18, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0xb, 0x1, 0xa, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe, 0xe, 0xe, 0x0, 0x0, 0xa, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x13, 0x18, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0xb, 0x0, 0xa, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x13, 0x6, 0xd, 0xd, 0x7, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x18, 0x4, 0x4, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0xb, 0x1, 0xa, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x1, 0x0, 0x17, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x18, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x24, 0x25, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0xe, 0x13, 0x13, 0x13, 0xe, 0xe, 0x1, 0xa, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x13, 0x14, 0x14, 0x14, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x19, 0x15, 0x10, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0xb, 0x0, 0xa, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x13, 0x14, 0x14, 0x14, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x18, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0xb, 0x0, 0xa, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x4, 0x4, 0x17, 0x13, 0x14, 0x14, 0x14, 0x13, 0x19, 0x15, 0x15, 0x15, 0x15, 0x10, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0xb, 0x2, 0xa, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x1, 0x0, 0x4, 0x4, 0x17, 0x13, 0x14, 0x14, 0x14, 0x13, 0x18, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x6, 0xd, 0x7, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x4, 0x4, 0x17, 0x13, 0x13, 0x13, 0x13, 0x13, 0x18, 0x4, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x4, 0xf, 0x15, 0x15, 0x15, 0x15, 0x15, 0x10, 0x4, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x1c, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x24, 0x25, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x1c, 0x24, 0x25, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x5, 0x4, 0x4, 0x4, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x20, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x20, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x14
};