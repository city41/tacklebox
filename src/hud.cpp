#include "hud.h"
#include "renderer.h"
#include "strings.h"

extern Renderer renderer;

void Hud::render(Player& player) {
    renderer.fillRect(0, 0, 24, 16, BLACK);
    renderer.drawNumber(2, 2, player.wormCount);
}

