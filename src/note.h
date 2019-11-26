#ifndef NOTE_H
#define NOTE_H

// Struct for a note played by keyboard or midi input

#include <QVector>

struct Note
{
    // The note with frequency 440 hz
    static const Note A4;

    Note(const float FREQUENCY);

    // The frequency when the note has begun
    float frequency;
};

#endif // NOTE_H
