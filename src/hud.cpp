#include "hud.h"
#include "state.h"
#include "renderer.h"
#include "strings.h"
#include "nonMaskBitmaps.h"

extern Renderer renderer;

void Hud::render(uint8_t frame, Player& player) {
    renderer.fillRect(0, 0, 25, 21, BLACK);

    renderer.drawOverwrite(3, 1, worm_tiles, 0, 0, Invert);
    renderer.drawNumber(13, 3, State::gameState.wormCount);

    // day night gauge
    renderer.drawOverwrite(1, 13, dayNightGauge_tiles, 0);
    renderer.drawOverwrite(State::gameState.hour, 11, dayNightNeedle_tiles, 0, 0, Xor);
}

