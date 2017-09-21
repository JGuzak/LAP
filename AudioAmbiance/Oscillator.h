// Author: Jordan Guzak

#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator {
public:
    Oscillator();
    void setStepAmt(float);
    void updateStep();
    float getCurPos();
    LEDColor updateColorCycle(LEDColor);

private:
    static const int MAX_STEPS = 1020;
    static const int QUARTER_STEPS = (MAX_STEPS / 4);
    float stepAmt, curStep;
};

#endif // !COLOR_OSCILLATOR_H
