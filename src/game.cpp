#include <Arduboy2.h>
#include "game.h"
#include "renderer.h"
#include "nonMaskBitmaps.h"
#include "maskBitmaps.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

/**
 * push a game state onto the "stack". The stack can only go two deep.
 * This is used to go from play -> inGameMenu, for example.
 */
void Game::push(UpdatePtr newUpdate, RenderPtr newRender) {
    nextUpdate = newUpdate;
    nextRender = newRender;
}

/**
 * Go back one level in the "stack", ie from inGameMenu back to play
 */
void Game::pop() {
    nextUpdate = prevUpdate;
    nextRender = prevRender;
}

void Game::updateLogo(uint8_t frame) {
    if (frame == 1) {
        push(&Game::updatePlay, &Game::renderPlay);
    }
}

void Game::renderLogo(uint8_t frame) {
    renderer.drawOverwrite(WIDTH / 2 - 8, HEIGHT / 2 - 4, city41Logo_tiles, 0);
}

void Game::updatePlay(uint8_t frame) {
    player.update(frame);
}

void Game::renderPlay(uint8_t frame) {
    player.render(frame);
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

