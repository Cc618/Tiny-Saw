#include "audiohandler.h"

AudioHandler::AudioHandler()
{
}

float AudioHandler::nextSample(const float dt)
{
    return _generator.nextSample(dt);
}
