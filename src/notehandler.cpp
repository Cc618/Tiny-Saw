#include "notehandler.h"

#include "audio.h"

#include <QRandomGenerator>

NoteHandler::NoteHandler(const int ID, const float FREQ, const Oscillator *OSC)
    : ID(ID)
{
    for (int i = 0; i < 8; ++i)
    {
        _voices.push_back(Voice(FREQ + audio::unisonPitch * static_cast<float>(i), static_cast<float>(qrand()) / static_cast<float>(RAND_MAX) * audio::unisonPhase, OSC));
        _voices.push_back(Voice(FREQ - audio::unisonPitch * static_cast<float>(i), static_cast<float>(qrand()) / static_cast<float>(RAND_MAX) * audio::unisonPhase, OSC));
    }
}

float NoteHandler::nextSample(const float dt)
{
    // Make the sum of all voices
    float sample = 0.f;
    for (Voice &voice : _voices)
    {
        // Generate the sample
        sample += voice.nextSample(dt);
    }

    return sample;
}

bool NoteHandler::operator==(const int ID) const
{
    return this->ID == ID;
}
