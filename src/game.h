#pragma once

#include "entities/player.h"
#include "entities/worm.h"

class Game {
    typedef void (Game::*UpdatePtr)(uint8_t);
    typedef void (Game::*RenderPtr)(uint8_t);

    public:
        Player player;

        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        uint8_t titleRow;
        uint8_t hour;        // what hour the game is at
        uint8_t seconds;     // actual seconds. 1 game hour = SECONDS_PER_HOUR real seconds


        void loadSave();

        void push(UpdatePtr newUpdate, RenderPtr newRender);
        void pop();

        void update(uint8_t frame);
        void render(uint8_t frame);

        void updateLogo(uint8_t frame);
        void renderLogo(uint8_t frame);

        void updateTitle(uint8_t frame);
        void renderTitle(uint8_t frame);

        void updatePlay(uint8_t frame);
        void renderPlay(uint8_t frame);

        void updateShop(uint8_t frame);
        void renderShop(uint8_t frame);

        Game(): 
            player(24 * 16, 10 * 16),
            prevUpdate(NULL),
            currentUpdate(&Game::updateLogo),
            nextUpdate(NULL),
            prevRender(NULL),
            currentRender(&Game::renderLogo),
            nextRender(NULL),
            titleRow(0),
            hour(12),
            seconds(0)
        {}
};

