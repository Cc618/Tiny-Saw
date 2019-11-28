#include "input.h"

#include <map>
// TODO : rm
#include <QDebug>
#include <QList>

#include "consts.h"
#include "soundgenerator.h"
#include "notehandler.h"

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
        'K',        // A2
        'O',        // A#2
        'L',        // B2
        ';',        // C2
        '[',        // C#2
        '\'',        // D2
        ']',        // D#2
        '\\',        // E2
    };

    // Frequencies for A to G# keys excluding sharps
    const float FREQ_TABLE[] = {
        440.f,          // A
        466.16f,        // A#
        493.88f,        // B
        523.25f,        // C
        554.37f,        // C#
        587.33f,        // D
        622.25f,        // D#
        659.25f,        // E
        698.46f,        // F
        739.99f,        // F#
        783.99f,        // G
        830.61f,        // G#
        440.f * 2.f,    // A2
        466.16f * 2.f,  // A#2
        493.88f * 2.f,  // B2
        523.25f * 2.f,  // C2
        554.37f * 2.f,  // C#2
        587.33f * 2.f,  // D2
        622.25f * 2.f,  // D#2
        659.25f * 2.f,  // E2
    };

    // To handle key presses after the audio synthesis
    // { ID, FREQUENCY }
    static QList<std::pair<int, float>> nextPressedKeys;
    // { ID }
    static QList<int> nextReleasedKeys;

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
                    nextPressedKeys.push_back(std::make_pair(offset, FREQ_TABLE[offset] * octaveFactor));
                else
                    nextReleasedKeys.push_back(offset);

                return true;
            }

            ++offset;
        }

        return false;
    }

    void triggerKeys()
    {
        // Trigger
        for (const auto &note : nextPressedKeys)
            SoundGenerator::instance->beginNote(note.first, note.second);

        for (const int ID : nextReleasedKeys)
            SoundGenerator::instance->endNote(ID);

        // Clear
        nextPressedKeys.clear();
        nextReleasedKeys.clear();
    }
}
