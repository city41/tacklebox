#include "animation.h"
#include "renderer.h"

void Animation::update() {
    if (done) {
        return;
    }

    currentFrameCounter -= 1;

    if (currentFrameCounter == 0) {
        moveToFrameIndex(currentFrameIndex + 1);
    }
}

void Animation::moveToFrameIndex(uint8_t frameIndex) {
    currentFrameIndex = frameIndex;
    currentFrameCounter = static_cast<uint8_t>(pgm_read_byte(durations + frameIndex * 2));

    done = currentFrameCounter == 255;

    if (!done) {
        currentFrame = static_cast<uint8_t>(pgm_read_byte(durations + frameIndex * 2 + 1));
    }
}

void Animation::reset() {
    moveToFrameIndex(0);
}
