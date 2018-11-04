#pragma once

#include <Arduino.h>
#include <EEPROM.h>

const uint8_t GAME_ID = 90;
const uint8_t EEPROM_START = 64;

const uint8_t DAY_NIGHT_BOUNDARY_HOUR = 15;

struct GameState {
    uint8_t hour;
    uint8_t wormCount;
    uint8_t fishCount;
};

class State {
    public:
        static GameState gameState;

        static bool hasUserSaved();
        static void saveToEEPROM();
        static void clearEEPROM();
        static void load();
};

