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
    for (const NoteHandler *NOTE : _notes)
        delete NOTE;

    delete _osc;
    delete _mix;
}

float SoundGenerator::nextSample(const float dt)
{
    // Make the sum of all voices
    float sample = 0.f;
    for (NoteHandler *note : _notes)
    {
        // Generate the sample
        sample += note->nextSample(dt);
    }

    return sample * _mix->nextVolume(dt);
}

void SoundGenerator::beginNote(const int ID, const float FREQUENCY)
{
    _notes.push_back(new NoteHandler(ID, FREQUENCY, _osc));
}

void SoundGenerator::endNote(const int ID)
{
    for (NoteHandler *NOTE : _notes)
        if (*NOTE == ID)
        {
            delete NOTE;

            // Try remove
            _notes.removeOne(NOTE);
            return;
        }
}
