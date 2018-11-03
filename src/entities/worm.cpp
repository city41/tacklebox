#include "worm.h"
#include "../renderer.h"
#include "../nonMaskBitmaps.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

void Worm::update(uint8_t frame, bool isActive, bool justBecameActive) {
    isSpawned = isSpawned || justBecameActive;
}

void Worm::render(uint8_t frame) {
    if (isSpawned) {
        renderer.drawOverwrite(x, y, worm_tiles, 0);
    }
}

void Worm::onGrabbedByPlayer() {
    isSpawned = false;
}
