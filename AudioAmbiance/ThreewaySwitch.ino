// Author: Jordan Guzak

#include "ThreewaySwitch.h"

ThreewaySwitch::ThreewaySwitch(int a, int b) {
    pin1 = a;
    pin2 = b;
    for (int i = 0; i < NUM_MODES; i++) {
        state[i] = 0;
    }
    pinMode(pin1, INPUT_PULLUP);
    pinMode(pin2, INPUT_PULLUP);
}

Switch_Position ThreewaySwitch::getPosition() {
    updateState();
    return position;
}

int* ThreewaySwitch::getState() {
    updateState();
    return state;
}

// TODO: test this
void ThreewaySwitch::updateState() {
    int newState;
    if (digitalRead(pin1) == HIGH) {
        newState = 0;
        position = DOWN;
    } else if (digitalRead(pin2) == HIGH) {
        newState = 1;
        position = CENTER;
    } else {
        newState = 2;
        position = UP;
    }

    for (int i = 0; i < NUM_STATES; i++) {
        state[i] = STATE[newState][i];
    }
    Serial.print(digitalRead(pin1));
    Serial.print(" ");
    Serial.print(digitalRead(pin2));
    Serial.println();
    // Serial.println(position);
}
