// Author: Jordan Guzak

#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator {
public:
    Oscillator();
    ~Oscillator() = default;

    void setOscSpeed(float);
    void updateStep();
    float getCurPos();

private:
    static const int MAX_STEPS = 1020;
    float curStep, position, stepAmt;
}

#endif // !OSCILLATOR_H