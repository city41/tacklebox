#ifndef hud_h
#define hud_h

#include <Arduino.h>
#include "entities/player.h"

class Hud {
    public:
        static void render(Player& player);
};

#endif

