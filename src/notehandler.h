#ifndef NOTEHANDLER_H
#define NOTEHANDLER_H

#include <QList>

#include "voice.h"
#include "oscillator.h"

class NoteHandler
{
public:
    NoteHandler(const int ID, const float FREQ, const Oscillator *OSC);

public:
    float nextSample(const float dt);

public:
    bool operator==(const int ID) const;

public:
    // To recognize the note handler when we type another key
    const int ID;

private:
    QList<Voice> _voices;
};

#endif // NOTEHANDLER_H
