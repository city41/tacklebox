#ifndef player_h
#define player_h

#include <Arduino.h>
#include "entity.h"
#include "../maskBitmaps.h"

class Player: public Entity {
    public:
        Player(int16_t px, int16_t py):
            Entity()
        {
            moveTo(px, py);
        }

        void render(uint8_t frame);
        void update(uint8_t frame);
};

#endif

