#ifndef tileFloor_h
#define tileFloor_h

#include <Arduino.h>
#include <Arduboy2.h>

enum TileDef: uint8_t {
    // begin - walkable tiles
    Blank = 0,
    FloorFlavor1,
    FloorFlavor2,
    ShopDoor,
    Sand,
    SandGrassBoundary,
    OceanSandBoundary,
    // end - walkable tiles

    // begin- solid tiles
    // begin -fishable tiles
    PondLowerLeftCorner,
    PondLowerRightCorner,
    PondUpperLeftCorner,
    PondUpperRightCorner,
    PondMiddle,
    PondMiddleDeep,
    PondLowerBoundary,
    PondUpperBoundary,
    PondLeftBoundary,
    PondRightBoundary,
    PondInnerCorner,
    Ocean,
    // end - fishable tiles
    BushWallLeft,
    BushWallRight,
    BushWallTop,
    BushWallBottom,
    BushWallLowerLeftCorner,
    BushWallLowerRightCorner,
    BushWallUpperLeftCorner,
    BushWallUpperRightCorner,
    BushLeft,
    BushRight,
    ShopLeftWall,
    ShopRightWall,
    ShopLeftSign,
    ShopCenterSign,
    ShopRightSign
    // end - solid tiles
};

struct TileFloor {
    static void renderTile(int16_t x, int16_t y, uint8_t tileId);
    static void renderCenteredOn(int16_t x, int16_t y);

    static TileDef getTileAt(int16_t x, int16_t y);

    static bool isWalkable(TileDef tile) {
        return tile <= OceanSandBoundary;
    }

    static bool isFishable(TileDef tile) {
        return tile >= PondLowerLeftCorner && tile <= Ocean;
    }
};

#endif

