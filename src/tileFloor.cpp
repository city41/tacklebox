#include "tileFloor.h"
#include "nonMaskBitmaps.h"
#include "util.h"
#include "drawBitmap.h"
#include "renderer.h"
#include "world.h"
#include "state.h"

extern Renderer renderer;

const uint8_t WATER_OFFSET = 28;
uint8_t TileFloor::waterAnimationOffset = 0;

TileDef TileFloor::getTileAt(int16_t x, int16_t y) {
    int16_t tileX = x / TILE_SIZE;
    int16_t tileY = y / TILE_SIZE;
    int16_t targetTileIndex = tileY * MAP_WIDTH_TILES + tileX;

    int16_t i = 0;

    while (i < WORLD_DATA_LENGTH) {
        const uint8_t iData = pgm_read_byte(world_map + i);
        bool jumpBy5 = iData & RL1;
        bool jumpBy3 = iData & RL2;

        int16_t nextI = jumpBy5 ? i + 5 : jumpBy3 ? i + 3 : i + 1;

        if (targetTileIndex >= i && targetTileIndex < nextI) {
            return static_cast<TileDef>(iData & 0x3F);
        }

        i = nextI;
    }
}

void TileFloor::renderTile(int16_t x, int16_t y, uint8_t tileId) {   
    if (isFishable(static_cast<TileDef>(tileId))) {
        tileId += WATER_OFFSET * waterAnimationOffset;
    }

    DrawMode drawMode = State::isDay() ? Normal : Invert;
    renderer.drawOverwrite(x, y, map_tiles, tileId, 0, drawMode);
}

void TileFloor::renderCenteredOn(int16_t x, int16_t y, uint8_t frame) {
    if (frame == 60) {
        waterAnimationOffset = 1 - waterAnimationOffset;
    }

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

