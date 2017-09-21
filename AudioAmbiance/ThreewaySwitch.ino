// Author: Jordan Guzak

#include "ThreewaySwitch.h"

ThreewaySwitch::ThreewaySwitch(int a, int b) {
    pin1 = a;
    pin2 = b;

    pinMode(pin1, INPUT_PULLUP);
    pinMode(pin2, INPUT_PULLUP);
}

Switch_Position ThreewaySwitch::getPosition() {
    updateState();
    return position;
}

int[] ThreewaySwitch::getState() {
    updateState();
    return state;
}

// TODO: test this
void ThreewaySwitch::updateState() {
    if (digitalRead(pin1) == LOW) {
        state = { 0, 0, 1 };
        position = DOWN;
    } else if (digitalRead(pin2) == LOW) {
        state = { 0, 1, 0 };
        position = CENTER;
    } else {
        state = { 1, 0, 0 };
        position = UP;
    }
    // Serial.println(position);
}
