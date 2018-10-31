#include "tileRoom.h"
#include "nonMaskBitmaps.h"
#include "util.h"
#include "drawBitmap.h"
#include "renderer.h"

extern Renderer renderer;

// header consists of
// map width (one byte)
// map height (one byte)
const uint8_t MAP_HEADER_SIZE = 2;

const uint8_t* TileRoom::map = NULL;
uint8_t TileRoom::x = 0;
uint8_t TileRoom::y = 0;

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

void TileRoom::renderTile(int16_t x, int16_t y, uint8_t tileId) {   
    TileDef tile = (TileDef)(tileId < 8 ? tileId : pgm_read_byte(mirroredTiles + (tileId - LowerLeftCorner) * 2));
    MirrorMode mirror = tileId < 8 ? 0 : pgm_read_byte(mirroredTiles + (tileId - LowerLeftCorner) * 2 + 1);
    bool dontInvert = true;
    DrawMode drawMode = dontInvert ? Normal : Invert;
    renderer.drawOverwrite(x, y, map_tiles, tile, mirror, drawMode);
}

void TileRoom::renderCenteredOn(int16_t x, int16_t y) {
    int8_t mapWidth = pgm_read_byte(TileRoom::map);
    int8_t mapHeight = pgm_read_byte(TileRoom::map + 1);
    int16_t maxTile = mapWidth * mapHeight;

    int16_t tileX = (x - WIDTH / 2) / 16;
    int16_t tileY = (y - HEIGHT / 2) / 16;
    int16_t firstTileIndex = tileY * mapWidth + tileX;
    int16_t shiftX = x % TILE_SIZE;
    int16_t shiftY = y % TILE_SIZE;


    for (uint8_t ty = 0; ty < 5; ++ty) {
        if (tileY + ty < 0 || tileY + ty >= mapHeight) {
            continue;
        }

        int16_t additionalRows = ty * mapWidth;

        for (uint8_t tx = 0; tx < 9; ++tx) {
            if (tileX + tx < 0 || tileX + tx >= mapWidth) {
                continue;
            }

            int16_t ti = firstTileIndex + additionalRows + tx;

            int16_t tileId = pgm_read_byte(TileRoom::map + 2 + ti);
            renderTile(tx * TILE_SIZE - shiftX, ty * TILE_SIZE - shiftY, tileId);
        }
    }
}

