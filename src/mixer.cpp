#include "mixer.h"

Mixer::Mixer(const float VOLUME)
    : _volume(VOLUME)
{
}

float Mixer::nextVolume(const float dt __attribute__((unused)))
{
    return _volume;
}
