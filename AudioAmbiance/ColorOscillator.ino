// Author: Jordan Guzak

#include "ColorOscillator.h"

ColorOscillator::ColorOscillator() {
    curStep = 0.0;
    stepAmt = 1.0;
}

/*
 * Sets the step amount as long as the value is between
 * 0 and 1.
 */
void ColorOscillator::setStepAmount(float newStepAmt) {
    if (newStepAmt < 1.0) {
        if (newStepAmt <= 0.0) {
            newStepAmt = 0.05;
        }
        stepAmt = newStepAmt * 25.0;
    }
}

void ColorOscillator::updateStep() {
    if (curStep > MAX_STEPS) {
        curStep = 0.0;
    }
    else {
        curStep += stepAmt;
    }
}

LEDColor ColorOscillator::updateColorCycle(LEDColor color) {
    updateStep();
    if (curStep >= 0 && curStep < MAX_STEPS) {
        if (curStep < (QUARTER_STEPS)) {
            color.W = (int)curStep;
            color.G = QUARTER_STEPS - (int)curStep;
        }
        else if (curStep < (QUARTER_STEPS * 2)) {
            color.B = (int)curStep % QUARTER_STEPS;
            color.R = QUARTER_STEPS - ((int)curStep % QUARTER_STEPS);
        }
        else if (curStep < (QUARTER_STEPS * 3)) {
            color.G = (int)curStep % QUARTER_STEPS;
            color.W = QUARTER_STEPS - ((int)curStep % QUARTER_STEPS);
        }
        else if (curStep < (QUARTER_STEPS * 4)) {
            color.R = (int)curStep % QUARTER_STEPS;
            color.B = QUARTER_STEPS - ((int)curStep % QUARTER_STEPS);
        }
    }

    return color;
}
