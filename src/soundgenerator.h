#ifndef SOUNDGENERATOR_H
#define SOUNDGENERATOR_H

// Used to generate sound with voices etc...

#include <QList>

#include "voice.h"
#include "note.h"

class SoundGenerator
{
public:
    // Singleton
    static SoundGenerator *instance;

public:
    SoundGenerator();
    ~SoundGenerator();

public:
    // Returns the generated sample
    // - dt : The time ellapsed since the last sample generation
    float nextSample(const float dt);

public:
    // Begin / End Voice
    void beginVoice(const Note &NOTE);
    void endVoice(const Note &NOTE);

private:
    QList<Voice> _voices;
    Mixer *_mix;
    Oscillator *_osc;
};

#endif // SOUNDGENERATOR_H
