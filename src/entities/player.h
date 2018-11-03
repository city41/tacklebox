#pragma once

#include <Arduboy2.h>
#include <Arduino.h>
#include "direction.h"
#include "worm.h"

class Player {
    typedef void (Player::*UpdatePtr)(uint8_t);
    typedef void (Player::*RenderPtr)(uint8_t);

    public:
        uint8_t wormCount;
        uint8_t fishCount;
        int16_t x;
        int16_t y;
        int16_t prevX;
        int16_t prevY;
        Direction dir;
        bool movedThisFrame;
        bool scanning;
        uint8_t holdACount;
        int16_t cursorX;
        int16_t cursorY;
        uint8_t castCount;
        uint8_t reelLevel;

        UpdatePtr currentUpdate;
        RenderPtr currentRender;

        Player(int16_t px, int16_t py):
            wormCount(0),
            fishCount(0),
            x(0),
            y(0),
            prevX(0),
            prevY(0),
            dir(DOWN),
            movedThisFrame(false),
            scanning(false),
            holdACount(0),
            castCount(0),
            reelLevel(0),
            currentUpdate(&Player::updateWalk),
            currentRender(&Player::renderWalk)
        {
            moveTo(px, py);
        }

        void render(uint8_t frame);
        void update(uint8_t frame);

        void updateWalk(uint8_t frame);
        void renderWalk(uint8_t frame);

        void updateScanning(uint8_t frame);
        void renderScanning(uint8_t frame);

        void updateCast(uint8_t frame);
        void renderCast(uint8_t frame);

        void updateReel(uint8_t frame);
        void renderReel(uint8_t frame);

        void updateGetFish(uint8_t frame);
        void renderGetFish(uint8_t frame);

        bool isOnSolidTile(void);
        void onGetWorm(Worm& worm);

        Direction determineDirection(int16_t px, int16_t py, int16_t x, int16_t y, Direction prevDir);
        void moveTo(int16_t newX, int16_t newY, boolean resetPrev = false);
        void undoMove();

};

