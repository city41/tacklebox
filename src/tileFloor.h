#ifndef tileFloor_h
#define tileFloor_h

#include <Arduino.h>
#include <Arduboy2.h>

enum TileDef: uint8_t {
    Blank = 0,
    UpperLeftCorner = 1,
    LeftWall = 2,
    LowerWall = 3,
    Stone = 4,
    Ladder = 5,
    Water = 6,
    Door = 7,

    // these tiles are mirrors of the above sprites
    LowerLeftCorner = 8,
    UpperRightCorner = 9,
    LowerRightCorner = 10,
    UpperWall = 11,
    RightWall = 12,
    Compression = 15
};

const uint8_t TILE_SIZE = 16;
const uint8_t TILES_PER_ROW = (WIDTH - 16) / TILE_SIZE;
const uint8_t TILES_PER_COLUMN = HEIGHT / TILE_SIZE;
const uint8_t TILES_PER_ROOM = TILES_PER_ROW * TILES_PER_COLUMN;

struct TileFloor {
    static const uint8_t* map;
    static uint8_t x;
    static uint8_t y;

    static void renderTile(int16_t x, int16_t y, uint8_t tileId);
    static void renderCenteredOn(int16_t x, int16_t y);

    static TileDef getTileAt(int16_t x, int16_t y);
};

#endif

