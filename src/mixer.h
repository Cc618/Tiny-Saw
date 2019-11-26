#ifndef MIXER_H
#define MIXER_H

// Modulates the volume of a voice

class Mixer
{
public:
    // Volume in [0, 1]
    Mixer(const float VOLUME);

public:
    // Returns the next volume value in [0, 1]
    // - dt : Ellapsed time since the last call
    float nextVolume(const float dt);

private:
    // [0, 1]
    float _volume;
};

#endif // MIXER_H
