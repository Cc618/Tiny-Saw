#ifndef SOUNDGENERATOR_H
#define SOUNDGENERATOR_H

// Used to generate sound with voices etc...

#include <qvector.h>

#include "voice.h"

class SoundGenerator
{
public:
    SoundGenerator();
    ~SoundGenerator();

public:
    // Returns the generated sample
    // - dt : The time ellapsed since the last sample generation
    float nextSample(const float dt);

private:
    QVector<Voice> _voices;
    Mixer *_mix;
    Oscillator *_osc;
};

#endif // SOUNDGENERATOR_H
