#ifndef INPUT_H
#define INPUT_H

// To handle keyboard / midi input

#include <QVector>

#include "note.h"

namespace input
{
    // Change the octave for the next note to play
    void changeCurrentOctave(const bool INCREASE);

    // - PRESSED : Whether the key event is a key press event
    // !!! The key must be an uppercase letter
    // Returns whether the key has been played
    bool triggerFromKey(const QChar key, const bool PRESSED);

    // Begin / end note
    void beginNote(const Note &NOTE);
    void endNote(const Note &NOTE);
};

#endif // INPUT_H