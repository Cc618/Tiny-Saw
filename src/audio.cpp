#include "audio.h"

#include <portaudio.h>

#include "consts.h"
#include "voice.h"

namespace audio
{
    // TODO : TESTS //
    // TODO : deletes
    static Oscillator *osc = new SawOscillator();
    static Mixer *mix = new Mixer(1.f);
    static Voice voice(440, 0, osc, mix);

    // Global Variables //
    static PaStream *stream;

    float mainVolume = .10f;

    // Intern Functions //
    // Main callback
    static int audioCallback(
        const void *inputBuffer __attribute__((unused)),
        void *outputBuffer,
        unsigned long samplesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo __attribute__((unused)),
        PaStreamCallbackFlags statusFlags __attribute__((unused)),
        void *userData __attribute__((unused)))
    {
        float *out = static_cast<float*>(outputBuffer);
        float sample;
        for (unsigned long i = 0; i < samplesPerBuffer; ++i)
        {
            sample = voice.nextSample(1.f / static_cast<float>(SAMPLE_RATE));

            // Clip sample
            if (sample <= -1.f)
                sample = -mainVolume;
            else if (sample >= 1.f)
                sample = mainVolume;
            else
                sample *= mainVolume;

            // Send to audio output
            *out++ = sample;
            *out++ = sample;
        }

        return 0;
    }

    // Extern Functions //
    bool init()
    {
        // Init Port Audio
        if (Pa_Initialize() != paNoError)
            return false;

        // Init audio stream
        if (Pa_OpenDefaultStream(&stream,
            0,          // No input
            2,          // Stereo
            paFloat32,  // Float output
            SAMPLE_RATE,
            256,        // Samples per buffer
            audioCallback,
            nullptr) != paNoError)
            return false;

        // Start stream
        return Pa_StartStream(stream) == paNoError;
    }

    bool terminate()
    {
        // Stop stream
        if (Pa_StopStream(stream) != paNoError)
            return false;

        // Close stream
        return Pa_CloseStream(stream) == paNoError;
    }
}