#pragma once

#include <Arduino.h>
#include "player.h"

struct Hud {
    public:
        static void render(uint8_t frame, Player& player);
};

