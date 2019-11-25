#ifndef AUDIO_H
#define AUDIO_H

// Audio functions

namespace audio
{
    extern float mainVolume;

    // Inits the audio
    bool init();

    // Terminates the audio
    bool terminate();
}

#endif // AUDIO_H
