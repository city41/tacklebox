#ifndef entity_h
#define entity_h

#include <Arduboy2.h>
#include "direction.h"

class Entity {
    protected:
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
    public:
        typedef void (*EntityUpdatePtr)(Entity* me, Entity& player, uint8_t frame);
        typedef void (*EntityCollideOtherEntityPtr)(Entity* me, Entity& other, Entity& player);

        EntityUpdatePtr updatePtr;
        EntityCollideOtherEntityPtr collideOtherEntityPtr;

        int16_t x;
        int16_t y;
        int16_t prevX;
        int16_t prevY;
        Direction dir;

        Entity():
            x(0),
            y(0),
            prevX(0),
            prevY(0),
            dir(DOWN)
        {}

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
};

#endif

