#include "note.h"

#include "input.h"

const Note Note::A4 = Note(440);

Note::Note(const float FREQUENCY)
    : frequency(FREQUENCY)
{
}
