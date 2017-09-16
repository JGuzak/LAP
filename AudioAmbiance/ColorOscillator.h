// Author: Jordan Guzak

#ifndef COLOR_OSCILLATOR_H
#define COLOR_OSCILLATOR_H

class ColorOscillator {
public:
    ColorOscillator();

    void setStepAmount(float);
    void updateStep();
    LEDColor updateColor(LEDColor);

private:
    static const int MAX_STEPS = 1020;
    static const int QUARTER_STEPS = (MAX_STEPS / 4);
    float stepAmt, curStep;
};

#endif // !COLOR_OSCILLATOR_H
