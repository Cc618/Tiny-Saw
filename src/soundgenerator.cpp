#include "soundgenerator.h"

// TODO : rm
#include <qdebug.h>

SoundGenerator *SoundGenerator::instance = nullptr;

SoundGenerator::SoundGenerator()
{
    instance = this;
    _osc = new SawOscillator();
    _mix = new Mixer(.16f);
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
    {
        // Generate the sample
        sample += voice.nextSample(dt);
    }

    return sample * _mix->nextVolume(dt);
}

void SoundGenerator::beginVoice(const Note &NOTE)
{
    _voices.push_back(Voice(NOTE.frequency, 0, _osc, _mix));
}

// TODO
#include <qdebug.h>

void SoundGenerator::endVoice(const Note &NOTE)
{
    for (const Voice &VOICE : _voices)
        if (VOICE._freq == NOTE.frequency)
        {
            // Try remove
            _voices.removeOne(VOICE);
            return;
        }
}
