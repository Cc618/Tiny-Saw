#include "soundgenerator.h"

SoundGenerator::SoundGenerator()
{
    _osc = new SawOscillator();
    _mix = new Mixer(.16f);

    // TODO : Move
    _voices.append(Voice(440, 0, _osc, _mix));
}

SoundGenerator::~SoundGenerator()
{
    delete _osc;
    delete _mix;
}

float SoundGenerator::nextSample(const float dt)
{
    // Make the sum of all voices
    float sample = 0.f;
    for (Voice &voice : _voices)
        sample += voice.nextSample(dt);

    return sample * _mix->nextVolume(dt);
}
