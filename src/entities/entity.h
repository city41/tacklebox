#ifndef entity_h
#define entity_h

#include <Arduboy2.h>

class Entity {
    public:
        typedef void (*EntityUpdatePtr)(Entity* me, Entity& player, uint8_t frame);
        typedef void (*EntityCollideOtherEntityPtr)(Entity* me, Entity& other, Entity& player);

        EntityUpdatePtr updatePtr;
        EntityCollideOtherEntityPtr collideOtherEntityPtr;

        int16_t x;
        int8_t y;
        int16_t prevX;
        int8_t prevY;

        Entity():
            x(0),
            y(0),
            prevX(0),
            prevY(0)
        {}

        inline void moveTo(int16_t newX, int8_t newY, boolean resetPrev = false) {
            if (resetPrev) {
                prevX = newX;
                prevY = newY;
            } else if (prevX != x || prevY != y) {
                prevX = x;
                prevY = y;
            }

            x = newX;
            y = newY;
        }
};

#endif

