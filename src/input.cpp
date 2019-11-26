#include "input.h"

// TODO : rm
#include <QDebug>
#include <QList>

#include "consts.h"
#include "soundgenerator.h"

namespace input
{
    // Attibutes //
    static short currentOctave = 4;
    static float octaveFactor = 1.f;

    // To get the semitone associated to a key
    static const QVector<QChar> keySemitoneOffset = {
        'A',        // A
        'W',        // A#
        'S',        // B
        'D',        // C
        'R',        // C#
        'F',        // D
        'T',        // D#
        'G',        // E
        'H',        // F
        'U',        // F#
        'J',        // G
        'I',        // G#
    };

    // Frequencies for A to G# keys excluding sharps
    const float FREQ_TABLE[] = {
        440.f,		// A
        466.16f,    // A#
        493.88f,	// B
        523.25f,	// C
        554.37f,	// C#
        587.33f,	// D
        622.25f,	// D#
        659.25f,	// E
        698.46f,	// F
        739.99f,	// F#
        783.99f,	// G
        830.61f,	// G#
    };

    // To handle key presses after the audio synthesis
    static QList<Note> nextPressedKeys,
        nextReleasedKeys;

    // Functions //
    void changeCurrentOctave(const bool INCREASE)
    {
        if (INCREASE && currentOctave < MAX_OCTAVE)
        {
            ++currentOctave;
            octaveFactor *= 2.f;
        }
        else if (currentOctave > MIN_OCTAVE)
        {
            --currentOctave;
            octaveFactor /= 2.f;
        }
    }

    bool triggerFromKey(const QChar key, const bool PRESSED)
    {
        unsigned short offset = 0;
        for (const QChar &c : keySemitoneOffset)
        {
            if (key == c)
            {
                if (PRESSED)
                    nextPressedKeys.push_back(Note(FREQ_TABLE[offset] * octaveFactor));
                else
                    nextReleasedKeys.push_back(Note(FREQ_TABLE[offset] * octaveFactor));

                return true;
            }

            ++offset;
        }

        return false;
    }

    void triggerKeys()
    {
        // Trigger
        for (const Note &note : nextPressedKeys)
            beginNote(note);

        for (const Note &note : nextReleasedKeys)
            endNote(note);

        // Clear
        nextPressedKeys.clear();
        nextReleasedKeys.clear();
    }

    void beginNote(const Note &NOTE)
    {
        SoundGenerator::instance->beginVoice(NOTE);
    }

    void endNote(const Note &NOTE)
    {
        SoundGenerator::instance->endVoice(NOTE);
    }
}
