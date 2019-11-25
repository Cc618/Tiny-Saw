#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H

#include "soundgenerator.h"

// Handles all audio elements within a synth

class AudioHandler
{
public:
    AudioHandler();

private:
    SoundGenerator _generator;
};

#endif // AUDIOHANDLER_H
