#include "boat.h"
#include "renderer.h"
#include "nonMaskBitmaps.h"
#include "state.h"

extern Renderer renderer;

int16_t Boat::x = 16 * 37;
int16_t Boat::y = 16 * 12;
int8_t Boat::frame = 0;

void Boat::render(uint8_t renderFrame) {
    if (renderFrame == 60) {
        frame = 1 - frame;
    }

    DrawMode drawMode = State::isDay() ? Normal : Invert;

    renderer.drawOverwrite(x, y, boat_tiles, frame, 0, drawMode);
}

