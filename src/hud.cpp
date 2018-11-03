#include "hud.h"
#include "state.h"
#include "renderer.h"
#include "strings.h"

extern Renderer renderer;

void Hud::render(Player& player) {
    renderer.fillRect(0, 0, 24, 16, BLACK);
    renderer.drawNumber(2, 2, State::gameState.wormCount);
    renderer.drawNumber(2, 8, State::gameState.fishCount);
}

