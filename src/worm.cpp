#include "worm.h"
#include "renderer.h"
#include "maskBitmaps.h"
#include "state.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

void Worm::update(uint8_t frame, bool isActive, bool justBecameActive) {
    isSpawned = isActive && (isSpawned || (justBecameActive && random(0, 3) == 0));
}

void Worm::render(uint8_t frame) {
    if (isSpawned) {
         renderer.drawPlusMask(x, y, worm_plus_mask, 0, static_cast<MirrorMode>(frame > 50), Xor);
    }
}

void Worm::onGrabbedByPlayer() {
    isSpawned = false;
}
