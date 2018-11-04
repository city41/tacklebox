#include "state.h"

GameState State::gameState = {};

bool State::hasUserSaved() {
    uint8_t id;
    EEPROM.get(EEPROM_START, id);

    return id == GAME_ID;
}

void State::saveToEEPROM() {
    EEPROM.write(EEPROM_START, GAME_ID);
    EEPROM.put(EEPROM_START + 1, gameState);
}

void State::load() {
    if (hasUserSaved()) {
        EEPROM.get(EEPROM_START + 1, gameState);
    } else {
        gameState.hour = 12;
        gameState.wormCount = 0;
        gameState.fishCount = 0;
    }
}

void State::clearEEPROM() {
    EEPROM.put(EEPROM_START, 0);
    load();
}

