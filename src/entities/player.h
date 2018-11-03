#pragma once

#include <Arduboy2.h>
#include <Arduino.h>
#include "direction.h"
#include "../maskBitmaps.h"

class Player {
    public:
        int16_t x;
        int16_t y;
        int16_t prevX;
        int16_t prevY;
        Direction dir;
        bool movedThisFrame;

        Player(int16_t px, int16_t py):
            x(0),
            y(0),
            prevX(0),
            prevY(0),
            dir(DOWN),
            movedThisFrame(false)
        {
            moveTo(px, py);
        }

        void render(uint8_t frame);
        void update(uint8_t frame);
        bool isOnSolidTile(void);

        Direction determineDirection(int16_t px, int16_t py, int16_t x, int16_t y, Direction prevDir) {
            if (px == x && py == y) {
                return prevDir;
            }

            if (px == x) {
                if (py > y) {
                    return UP;
                }
                return DOWN;
            } else {
                if (px > x) {
                    return LEFT;
                }
                return RIGHT;
            }
        }

        inline void moveTo(int16_t newX, int16_t newY, boolean resetPrev = false) {
            if (resetPrev) {
                prevX = newX;
                prevY = newY;
            } else if (prevX != x || prevY != y) {
                prevX = x;
                prevY = y;
            }

            x = newX;
            y = newY;

            dir = determineDirection(prevX, prevY, x, y, dir);
        }

        inline void undoMove() {
            x = prevX;
            y = prevY;
        }
};

