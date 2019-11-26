#ifndef INPUT_H
#define INPUT_H

// To handle keyboard / midi input

#include <QVector>

#include "notehandler.h"

namespace input
{
    // Change the octave for the next note to play
    void changeCurrentOctave(const bool INCREASE);

    // - PRESSED : Whether the key event is a key press event
    // !!! The key must be an uppercase letter
    // Returns whether the key has been played
    bool triggerFromKey(const QChar key, const bool PRESSED);

    // Triggers the keys when we don't use the synth
    void triggerKeys();
};

#endif // INPUT_H
