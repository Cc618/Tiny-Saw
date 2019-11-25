#ifndef VOICE_H
#define VOICE_H

// A voice to generate audio for one key

#include <oscillator.h>
#include <mixer.h>

class Voice
{
public:
    Voice(const float FREQ, const float PHASE, const Oscillator *osc, const Mixer *mixer);

public:
    // Returns the generated sample
    // - dt : The time ellapsed since the last sample generation
    float nextSample(const float dt);

private:
    float _freq,
        _phase;

    const Oscillator *_osc;
    const Mixer *_mixer;
};

#endif // VOICE_H