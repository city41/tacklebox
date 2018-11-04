#include "tileFloor.h"
#include "nonMaskBitmaps.h"
#include "util.h"
#include "drawBitmap.h"
#include "renderer.h"
#include "world.h"
#include "state.h"

extern Renderer renderer;

const uint8_t PROGMEM mirroredTiles[] = {
    UpperLeftCorner,
    MIRROR_VERTICAL,
    UpperLeftCorner,
    MIRROR_HORIZONTAL,
    UpperLeftCorner,
    MIRROR_HORIZONTAL | MIRROR_VERTICAL,
    LowerWall,
    MIRROR_VERTICAL,
    LeftWall,
    MIRROR_HORIZONTAL
};

TileDef TileFloor::getTileAt(int16_t x, int16_t y) {
    int16_t tileX = x / TILE_SIZE;
    int16_t tileY = y / TILE_SIZE;
    int16_t firstTileIndex = tileY * MAP_WIDTH_TILES + tileX;

    return (TileDef)pgm_read_byte(world_map + firstTileIndex);
}

void TileFloor::renderTile(int16_t x, int16_t y, uint8_t tileId) {   
    TileDef tile = (TileDef)(tileId < 8 ? tileId : pgm_read_byte(mirroredTiles + (tileId - LowerLeftCorner) * 2));
    MirrorMode mirror = tileId < 8 ? 0 : pgm_read_byte(mirroredTiles + (tileId - LowerLeftCorner) * 2 + 1);
    DrawMode drawMode = State::isDay() ? Normal : Invert;
    renderer.drawOverwrite(x, y, map_tiles, tile, mirror, drawMode);
}

void TileFloor::renderCenteredOn(int16_t x, int16_t y) {
    int16_t maxTile = MAP_WIDTH_TILES * MAP_HEIGHT_TILES;

    int16_t tileX = (x - WIDTH / 2) / TILE_SIZE;
    int16_t tileY = (y - HEIGHT / 2) / TILE_SIZE;
    int16_t firstTileIndex = tileY * MAP_WIDTH_TILES + tileX;
    int16_t shiftX = x % TILE_SIZE;
    int16_t shiftY = y % TILE_SIZE;


    for (uint8_t ty = 0; ty < 5; ++ty) {
        int16_t additionalRows = ty * MAP_WIDTH_TILES;

        for (uint8_t tx = 0; tx < 9; ++tx) {
            int16_t ti = firstTileIndex + additionalRows + tx;

            int16_t tileId = pgm_read_byte(world_map + ti);
            renderTile(tx * TILE_SIZE - shiftX, ty * TILE_SIZE - shiftY, tileId);
        }
    }
}

