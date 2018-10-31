#ifndef gameScene_h
#define gameScene_h

class Game {
    typedef void (Game::*UpdatePtr)(uint8_t);
    typedef void (Game::*RenderPtr)(uint8_t);

    private:
        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        void updateLogo(uint8_t frame);
        void renderLogo(uint8_t frame);

    public:
        void update(uint8_t frame);
        void render(uint8_t frame);

        Game(): 
            prevUpdate(NULL),
            currentUpdate(&Game::updateLogo),
            nextUpdate(NULL),
            prevRender(NULL),
            currentRender(&Game::renderLogo),
            nextRender(NULL)
        {}
};

#endif

