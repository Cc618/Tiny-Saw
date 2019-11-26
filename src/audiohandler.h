#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H

#include "soundgenerator.h"

// Handles all audio elements within a synth

class AudioHandler
{
public:
    AudioHandler();

public:
    // Returns the generated sample
    // - dt : The time ellapsed since the last sample generation
    float nextSample(const float dt);

private:
    SoundGenerator _generator;
};

#endif // AUDIOHANDLER_H
