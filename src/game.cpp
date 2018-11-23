#include <Arduboy2.h>
#include "game.h"
#include "renderer.h"
#include "nonMaskBitmaps.h"
#include "maskBitmaps.h"
#include "strings.h"
#include "tileFloor.h"
#include "world.h"
#include "hud.h"
#include "shop.h"
#include "worms.h"
#include "girl.h"
#include "boat.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

const uint8_t SECONDS_PER_MINUTE = 1;
const uint16_t MINUTES_IN_A_DAY = 24 * 60;

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

void Game::updateTitle(uint8_t frame) {
    titleCount += 1;
    if (titleCount == 120) {
        push(&Game::updatePlay, &Game::renderPlay);
    }
}

void Game::renderTitle(uint8_t frame) {
    renderer.drawOverwrite(20, 16, logo_tiles, 0);
    renderer.drawOverwrite(WIDTH - 24, HEIGHT - 8, city41Logo_tiles, 0);
}

bool isOnScreen(int16_t refX, int16_t refY, int16_t x, int16_t y) {
    return (refX - WIDTH / 2 <= x && refX + WIDTH / 2 >= x) &&
        (refY - HEIGHT / 2 <= y && refY + HEIGHT / 2 >= y);
}

bool overlap(Player& player, Worm& worm) {
    return !(
        worm.x     >= player.x + 16  ||
        worm.x + 8 <= player.x       ||
        worm.y     >= player.y + 16  ||
        worm.y + 8 <= player.y
    );
}

void Game::updatePlay(uint8_t frame) {
    if (frame == 60) {
        seconds += 1;

        if (seconds == SECONDS_PER_MINUTE) {
            seconds = 0;
            State::gameState.minute += 1;

            if (State::gameState.minute == MINUTES_IN_A_DAY) {
                State::gameState.minute = 0;
            }
        }
    }

    player.update(frame);

    bool isActive = isOnScreen(player.x, player.y, Girl::x, Girl::y);
    bool justBecameActive = isActive && !isOnScreen(player.prevX, player.prevY, Girl::x, Girl::y);
    Girl::update(isActive, justBecameActive);

    if (TileFloor::getTileAt(player.x, player.y) == ShopDoor) {
        Shop::onEnter();
        push(&Game::updateShop, &Game::renderShop);
        return;
    }

    for (uint8_t w = 0; w < MAX_WORMS; ++w) {
        isActive = isOnScreen(player.x, player.y, worms[w].x, worms[w].y);
        justBecameActive = isActive && !isOnScreen(player.prevX, player.prevY, worms[w].x, worms[w].y);
        worms[w].update(frame, isActive, justBecameActive);

        if (overlap(player, worms[w])) {
            player.onGetWorm(worms[w]);
            worms[w].onGrabbedByPlayer();
        }
    }
}

void Game::renderPlay(uint8_t frame) {
    int16_t centerX = min(max(WIDTH / 2, player.x), MAP_WIDTH_PX - WIDTH / 2);
    int16_t centerY = min(max(HEIGHT / 2, player.y), MAP_HEIGHT_PX - HEIGHT / 2);

    TileFloor::renderCenteredOn(centerX, centerY);

    // translate the renderer based on the player's location
    // essentially the same as translating a camera in a 3d game
    int16_t translateX;
    int16_t translateY;

    if (player.x < WIDTH / 2) {
        translateX = 0;
    } else if (player.x > MAP_WIDTH_PX - WIDTH / 2) {
        translateX = WIDTH - MAP_WIDTH_PX;
    } else {
        translateX = -player.x + WIDTH / 2;
    }

    if (player.y < HEIGHT / 2) {
        translateY = 0;
    } else if (player.y > MAP_HEIGHT_PX - HEIGHT / 2) {
        translateY = HEIGHT - MAP_HEIGHT_PX;
    } else {
        translateY = -player.y + HEIGHT / 2;
    }

    renderer.translateX = translateX;
    renderer.translateY = translateY;

    for (uint8_t w = 0; w < MAX_WORMS; ++w) {
        bool isActive = isOnScreen(player.x, player.y, worms[w].x, worms[w].y);

        if (isActive) {
            worms[w].render(frame);
        }
    }

    Girl::render(frame);
    Boat::render(frame);
    player.render(frame);

    renderer.translateX = WIDTH - 64;
    renderer.translateY = 0;
    Hud::render(player);
}

void Game::updateShop(uint8_t frame) {
    if (arduboy.justPressed(B_BUTTON) && Shop::currentUpdate == &Shop::updateMainMenu) {
        player.moveTo(player.x, player.y + 16);
        pop();
    } else {
        Shop::update(frame);
    }
}

void Game::renderShop(uint8_t frame) {
    Shop::render(frame);
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

