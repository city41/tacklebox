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
#include "signs.h"
#include "girl.h"
#include "boat.h"
#include "util.h"

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

bool overlap(Player& player, const int16_t otherX, const int16_t otherY, const int8_t otherW, const int8_t otherH) {
    return !(
        otherX          >= player.x + 16  ||
        otherX + otherW <= player.x       ||
        otherY          >= player.y + 16  ||
        otherY + otherH <= player.y
    );
}

bool Game::isOnShopDoor() {
    return (    
        player.dir == UP &&
        player.y <= 20 &&
        (
            TileFloor::getTileAt(player.x + 8, player.y) == ShopDoor
        )
    );
}

bool Game::isOnBoat() {
    if (Boat::currentDock == Dock::Beach) {
        return (
            player.dir == UP &&
            player.x >= Boat::x - 4 &&
            player.y >= Boat::y
        );
    } else {
        return (
            player.dir == UP &&
            player.x <= Boat::x + 4 &&
            player.y >= Boat::y
        );
    }
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

    if (isOnShopDoor() && Shop::isOpen()) {
        Shop::onEnter();
        push(&Game::updateShop, &Game::renderShop);
        return;
    }

    if (isOnBoat() && State::gameState.hasOars) {
        Boat::onEnter();
        push(&Game::updateBoatTravel, &Game::renderBoatTravel);
        return;
    }

    for (uint8_t w = 0; w < MAX_WORMS; ++w) {
        isActive = isOnScreen(player.x, player.y, worms[w].x, worms[w].y);
        justBecameActive = isActive && !isOnScreen(player.prevX, player.prevY, worms[w].x, worms[w].y);
        worms[w].update(frame, isActive, justBecameActive);

        if (overlap(player, worms[w].x, worms[w].y, 8, 8)) {
            player.onGetWorm(worms[w]);
            worms[w].onGrabbedByPlayer();
        }
    }



    for (uint8_t s = 0; s < MAX_SIGNS; ++s) {
        if (overlap(player, signs[s].x, signs[s].y, 12, 6)) {
            player.undoMove();
            currentSignMessage = signs[s].message;
            currentSignMessageCount = 90;
        }
    }

    if (currentSignMessageCount > 0) {
        currentSignMessageCount -= 1;
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
        worms[w].render(frame);
    }

    for (uint8_t s = 0; s < MAX_SIGNS; ++s) {
        signs[s].render();
    }

    Girl::render(frame);
    Boat::render(frame);

    if (!Shop::isOpen()) {
        renderer.drawOverwrite(16 * 25 - 5, 20, closed_tiles, 0);
    }

    player.render(frame);

    renderer.translateX = WIDTH - 64;
    renderer.translateY = 0;
    Hud::render(player);

    if (currentSignMessageCount > 0) {
        renderer.translateX = 0;
        renderer.translateY = 0;
        renderer.fillRect(0, HEIGHT - 6, WIDTH, 6, BLACK);
        renderer.drawString(1, HEIGHT - 5, currentSignMessage);
    }

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

void Game::updateBoatTravel(uint8_t frame) {
    Boat::update(frame);

    if (Boat::arrived) {
        if (Boat::currentDock == Dock::Island) {
            player.moveTo(Boat::x + 8, Boat::y + 16, true);
            player.dir = RIGHT;
        } else {
            player.moveTo(Boat::x, Boat::y + 16, true);
            player.dir = LEFT;
        }
        pop();
    }
}

void Game::renderBoatTravel(uint8_t frame) {
    const int16_t boatX = Boat::x + 2;
    const int16_t boatY = Boat::y + 16;

    TileFloor::renderCenteredOn(boatX, boatY);


    int16_t translateX;
    int16_t translateY;

    // TODO: this only needs to account for the right side of the map
    if (boatX < WIDTH / 2) {
        translateX = 0;
    } else if (boatX > MAP_WIDTH_PX - WIDTH / 2) {
        translateX = WIDTH - MAP_WIDTH_PX;
    } else {
        translateX = -boatX + WIDTH / 2;
    }

    if (boatY < HEIGHT / 2) {
        translateY = 0;
    } else if (boatY > MAP_HEIGHT_PX - HEIGHT / 2) {
        translateY = HEIGHT - MAP_HEIGHT_PX;
    } else {
        translateY = -boatY + HEIGHT / 2;
    }

    renderer.translateX = translateX;
    renderer.translateY = translateY;

    for (uint8_t s = 0; s < MAX_SIGNS; ++s) {
        signs[s].render();
    }

    Boat::render(frame);
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

