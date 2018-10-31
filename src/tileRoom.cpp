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

void TileRoom::renderTile(uint8_t x, uint8_t y, uint8_t tileId, uint8_t seed) {   
    // algorithmically draw "flavor" in blank spots. this gets us flowers in the overworld
    // without wasting a tile. Only doing this in the overworld as flavor in the dungeons
    // doesn't look good
    if (tileId == 0 && (seed % 7 == 1)) {
        renderer.drawOverwrite(x, y, map_tiles, 8, seed);
        return;
    }

    TileDef tile = (TileDef)(tileId < 8 ? tileId : pgm_read_byte(mirroredTiles + (tileId - LowerLeftCorner) * 2));
    MirrorMode mirror = tileId < 8 ? 0 : pgm_read_byte(mirroredTiles + (tileId - LowerLeftCorner) * 2 + 1);
    bool dontInvert = true;
    DrawMode drawMode = dontInvert ? Normal : Invert;
    renderer.drawOverwrite(x, y, map_tiles, tile, mirror, drawMode);
}

void TileRoom::renderCenteredOn(uint8_t x, uint8_t y) {
    uint8_t mapWidth = pgm_read_byte(TileRoom::map);

    uint8_t tileX = (x - WIDTH / 2) / 16;
    uint8_t tileY = (y - HEIGHT / 2) / 16;
    uint8_t firstTileId = tileY * mapWidth + tileX;
    uint8_t seed = 0;


    for (uint8_t ty = 0; ty < 4; ++ty) {
        uint8_t additionalRows = ty * mapWidth;

        for (uint8_t tx = 0; tx < 7; ++tx) {
            uint8_t ti = firstTileId + additionalRows + tx;
            uint8_t tileId = pgm_read_byte(TileRoom::map + 2 + ti);
            seed += tileId + 1;

            renderTile(tx * TILE_SIZE, ty * TILE_SIZE, tileId, seed);
        }
    }
}

