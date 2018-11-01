#include <Arduboy2.h>
#include "game.h"
#include "renderer.h"
#include "nonMaskBitmaps.h"
#include "maskBitmaps.h"
#include "strings.h"
#include "tileFloor.h"
#include "overworld.h"
#include "hud.h"

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
        push(&Game::updateTitle, &Game::renderTitle);
    }
}

void Game::renderLogo(uint8_t frame) {
    renderer.drawOverwrite(WIDTH / 2 - 8, HEIGHT / 2 - 4, city41Logo_tiles, 0);
}

const uint8_t PLAY_GAME = 0;
const uint8_t SFX_ON_OFF = 1;
const uint8_t DELETE_SAVE = 2;

void Game::updateTitle(uint8_t frame) {
    if (arduboy.justPressed(A_BUTTON)) {
        if (titleRow == PLAY_GAME) {
            /* loadSave(); */
            push(&Game::updatePlay, &Game::renderPlay);
        /* } else if (titleRow == DELETE_SAVE) { */
        /*     titleRow = 0; */
        /*     State::clearEEPROM(); */
        } else if (titleRow == SFX_ON_OFF) {
            Arduboy2Audio::toggle();
            Arduboy2Audio::saveOnOff();
        }
    }

    uint8_t rows = /*State::hasUserSaved() ? 2 : */ 1;

    if (arduboy.justPressed(UP_BUTTON)) {
        titleRow = max(titleRow - 1, 0);
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
        titleRow = min(titleRow + 1, rows);
    }
}

void Game::renderTitle(uint8_t frame) {
    const uint8_t* startGameLabel = newGame_string;

    renderer.drawString(42, 42, startGameLabel);
    renderer.drawString(42, 50, Arduboy2Audio::enabled() ? sfxOn_string : sfxOff_string);

    /* if (State::hasUserSaved()) { */
    /*     renderer.drawString(42, 58, deleteSave_string); */
    /* } */

    renderer.drawOverwrite(34,42 + titleRow * 8, squareIcon_tiles, 2);
}

void Game::updatePlay(uint8_t frame) {
    player.update(frame);
}

void Game::renderPlay(uint8_t frame) {
    int16_t centerX = min(max(WIDTH / 2, player.x), MAP_WIDTH_PX - WIDTH / 2);
    int16_t centerY = min(max(HEIGHT / 2, player.y), MAP_HEIGHT_PX - HEIGHT / 2);

    TileFloor::renderCenteredOn(centerX, centerY);
    player.render(frame);

    renderer.translateX = WIDTH - 24;
    Hud::render(player);
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

