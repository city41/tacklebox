#pragma once

#include <Arduino.h>

class Animation {
    public:
        uint8_t currentFrameIndex;
        uint8_t currentFrame;
        uint8_t currentFrameCounter;

        const uint8_t* durations;
        bool done;
    
        void update();
        void reset();
        void moveToFrameIndex(uint8_t frameIndex);

        Animation(const uint8_t* durations):
            currentFrameIndex(0),
            durations(durations)
        {
            moveToFrameIndex(0);
        }
};

