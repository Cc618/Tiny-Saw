#include "voice.h"

#include <cmath>

Voice::Voice()
    : _freq(0), _phase(0), _osc(nullptr), _mixer(nullptr)
{}

Voice::Voice(const float FREQ, const float PHASE, const Oscillator *osc, const Mixer *mixer)
    : _freq(FREQ), _phase(PHASE), _osc(osc), _mixer(mixer)
{}

float Voice::nextSample(const float dt)
{
    // TODO : Update mixer
    // Update phase
    _phase += dt * _freq;
    _phase = fmodf(_phase, 1.f);

    return _osc->getSample(_phase);
}

bool Voice::operator==(const Voice &v) const
{
    // TODO : Move in NoteHandler
    return _freq == v._freq;
}
