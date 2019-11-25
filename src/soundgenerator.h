#ifndef SOUNDGENERATOR_H
#define SOUNDGENERATOR_H

// Used to generate sound with voices etc...

#include <qvector.h>

#include "voice.h"

class SoundGenerator
{
public:
    SoundGenerator();

private:
    QVector<Voice> _voices;
};

#endif // SOUNDGENERATOR_H
