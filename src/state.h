#pragma once

#include <Arduino.h>
#include <EEPROM.h>
#include "fishType.h"

const uint8_t GAME_ID = 90;
const uint8_t EEPROM_START = 64;

struct GameState {
    uint16_t minute;
    uint8_t wormCount;
    uint8_t fishCount;
    bool acquiredFish[static_cast<int8_t>(FishType::NUM_FISH)];
};

class State {
    public:
        static GameState gameState;

        static void setFishAcquired(FishType fishType);

        static bool hasUserSaved();
        static void saveToEEPROM();
        static void clearEEPROM();
        static void load();

        static bool isDay();
        static uint8_t getCurrentHour();
};

