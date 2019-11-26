#include "notehandler.h"

NoteHandler::NoteHandler(const int ID, const float FREQ, const Oscillator *OSC)
    : ID(ID)
{
    _voices.push_back(Voice(FREQ, 0, OSC));
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
