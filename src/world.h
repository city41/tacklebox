
#pragma once

#include <Arduino.h>

const int16_t TILE_SIZE = 16;
const int16_t MAP_WIDTH_TILES = 49;
const int16_t MAP_HEIGHT_TILES = 24;
const int16_t MAP_WIDTH_PX = MAP_WIDTH_TILES * TILE_SIZE;
const int16_t MAP_HEIGHT_PX = MAP_HEIGHT_TILES * TILE_SIZE;

uint8_t world_getTileAt(int16_t x, int16_t y);
