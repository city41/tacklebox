#include <Arduboy2.h>
#include "game.h"
#include "renderer.h"
#include "nonMaskBitmaps.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

void Game::updateLogo(uint8_t frame) {
}

void Game::renderLogo(uint8_t frame) {
    renderer.drawOverwrite(WIDTH / 2 - 8, HEIGHT / 2 - 4, city41Logo_tiles, 0);
}

void Game::update(uint8_t frame) {
    (this->*currentUpdate)(frame);

    if (nextUpdate != NULL) {
        prevUpdate = currentUpdate;
        currentUpdate = nextUpdate;
        nextUpdate = NULL;
    }

}

void Game::render(uint8_t frame) {
    renderer.translateX = 0;
    renderer.translateY = 0;

    (this->*currentRender)(frame);

    if (nextRender != NULL) {
        prevRender = currentRender;
        currentRender = nextRender;
        nextRender = NULL;
    }
}

