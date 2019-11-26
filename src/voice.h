#ifndef VOICE_H
#define VOICE_H

// A voice to generate audio for one key

#include <oscillator.h>
#include <mixer.h>

class Voice
{
public:
    Voice();
    Voice(const float FREQ, const float PHASE, const Oscillator *osc);

public:
    // Returns the generated sample
    // - dt : The time ellapsed since the last sample generation
    float nextSample(const float dt);

public:
    // TODO : Move in private
    float _freq;

private:
    float _phase;

    const Oscillator *_osc;
};

#endif // VOICE_H
