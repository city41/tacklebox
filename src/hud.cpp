#include "hud.h"
#include "renderer.h"
#include "strings.h"

extern Renderer renderer;

void Hud::render(Player& player) {
    renderer.fillRect(0, 0, 24, 16, BLACK);
    renderer.drawString(2, 2, sfxOff_string);
    renderer.drawNumber(2, 8, 729);
}

