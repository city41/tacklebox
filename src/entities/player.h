#ifndef player_h
#define player_h

#include <Arduino.h>
#include "entity.h"
#include "../maskBitmaps.h"

class Player: public Entity {
    public:
        bool movedThisFrame;

        Player(int16_t px, int16_t py):
            Entity(),
            movedThisFrame(false)
        {
            moveTo(px, py);
        }

        void render(uint8_t frame);
        void update(uint8_t frame);
};

#endif

