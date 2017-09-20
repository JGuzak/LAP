// Author: Jordan Guzak

#include "Oscillator.h"
#include "ExtraFunctions.h"

Oscillator::Oscillator() {
    position = 0.0;
    stepAmt = 1.0;
}

void Oscillator::setOscSpeed(float newStepAmt) {
    if (newStepAmt < 1.0) {
        if (newStepAmt <= 0.0) {
            newStepAmt = 0.05;
        }
        stepAmt = newStepAmt * 25.0;
    }
}

void Oscillator::updateStep() {
    if (curStep > MAX_STEPS) {
        curStep = 0.0;
    }
    else {
        curStep += stepAmt;
    }
}

float Oscillator::getCurPos() {
    float curRadian = mapFloat(curStep, 0, MAX_STEPS, 0, 2.0);
    return sin(curRadian);
}