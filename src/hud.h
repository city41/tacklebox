#pragma once

#include <Arduino.h>
#include "entities/player.h"

class Hud {
    public:
        static void render(Player& player);
};

