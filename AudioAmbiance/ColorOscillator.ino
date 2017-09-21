// Author: Jordan Guzak

#include "Oscillator.h"

Oscillator::Oscillator() {
    curStep = 0.0;
    stepAmt = 1.0;
}

/*
 * Sets the step amount as long as the value is between
 * 0 and 1.
 */
void Oscillator::setStepAmt(float newStepAmt) {
    if (newStepAmt < 1.0) {
        if (newStepAmt <= 0.0) {
            newStepAmt = 0.05;
        }
        stepAmt = newStepAmt * 25.0;
        // Serial.println(stepAmt);
    }
}

void Oscillator::updateStep() {
    if (curStep > MAX_STEPS) {
        curStep = 0.0;
    }
    else {
        curStep += stepAmt;
        // Serial.println(curStep);
        
    }
}

float Oscillator::getCurPos() {
    float curRadian = mapFloat(curStep, 0, MAX_STEPS, 0, 2.0);
    return sin(curRadian);
}

LEDColor Oscillator::updateColorCycle(LEDColor color) {
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
