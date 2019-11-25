#ifndef OSCILLATOR_H
#define OSCILLATOR_H

// Provides the sound wave's shape

class Oscillator
{
public:
    Oscillator();
    virtual ~Oscillator();

public:
    // Returns the sample associated to PHASE in [0, 1]
    // The returned value is within [-1, 1]
    virtual float getSample(const float PHASE) const = 0;
};

class SawOscillator : public Oscillator
{
public:
    virtual float getSample(const float PHASE) const override;
};

#endif // OSCILLATOR_H
