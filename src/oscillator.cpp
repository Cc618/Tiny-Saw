#include "oscillator.h"

Oscillator::Oscillator()
{
}

Oscillator::~Oscillator()
{
}

float SawOscillator::getSample(const float PHASE) const
{
    return PHASE * 2.f - 1.f;
}
