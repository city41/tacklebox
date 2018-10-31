#ifndef gameScene_h
#define gameScene_h

#include "entities/player.h"

class Game {
    typedef void (Game::*UpdatePtr)(uint8_t);
    typedef void (Game::*RenderPtr)(uint8_t);

    private:
        Player player;

        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        void push(UpdatePtr newUpdate, RenderPtr newRender);
        void pop();

        void updateLogo(uint8_t frame);
        void renderLogo(uint8_t frame);

    public:
        void update(uint8_t frame);
        void render(uint8_t frame);

        void updatePlay(uint8_t frame);
        void renderPlay(uint8_t frame);

        Game(): 
            player(WIDTH / 2, HEIGHT / 2),
            prevUpdate(NULL),
            currentUpdate(&Game::updateLogo),
            nextUpdate(NULL),
            prevRender(NULL),
            currentRender(&Game::renderLogo),
            nextRender(NULL)
        {}
};

#endif

