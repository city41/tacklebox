#pragma once

#include "entities/player.h"
#include "entities/worm.h"

const uint8_t MAX_WORMS = 1;

class Game {
    typedef void (Game::*UpdatePtr)(uint8_t);
    typedef void (Game::*RenderPtr)(uint8_t);

    public:
        bool firstPlayFrame;
        Player player;
        Worm worms[MAX_WORMS];

        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        void loadSave();

        void push(UpdatePtr newUpdate, RenderPtr newRender);
        void pop();

        void update(uint8_t frame);
        void render(uint8_t frame);

        void updateLogo(uint8_t frame);
        void renderLogo(uint8_t frame);

        void updateTitle(uint8_t frame);
        void renderTitle(uint8_t frame);
        uint8_t titleRow;

        void updatePlay(uint8_t frame);
        void renderPlay(uint8_t frame);

        Game(): 
            player(24 * 16, 10 * 16),
            worms({ Worm(25 * 16, 10 * 16)}),
            prevUpdate(NULL),
            currentUpdate(&Game::updateLogo),
            nextUpdate(NULL),
            prevRender(NULL),
            currentRender(&Game::renderLogo),
            nextRender(NULL),
            titleRow(0)
        {}
};

