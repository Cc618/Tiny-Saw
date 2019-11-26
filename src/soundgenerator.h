#ifndef SOUNDGENERATOR_H
#define SOUNDGENERATOR_H

// Used to generate sound with voices etc...

#include <QList>

#include "voice.h"
#include "notehandler.h"

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
    // Begin / End Note
    void beginNote(const int ID, const float FREQUENCY);
    void endNote(const int ID);

private:
    QList<NoteHandler*> _notes;
    Mixer *_mix;
    Oscillator *_osc;
};

#endif // SOUNDGENERATOR_H
