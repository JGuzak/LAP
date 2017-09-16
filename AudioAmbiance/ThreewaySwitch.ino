// Author: Jordan Guzak

#include "ThreewaySwitch.h"

ThreewaySwitch::ThreewaySwitch(int a, int b) {
    pin1 = a;
    pin2 = b;

    pinMode(pin1, INPUT_PULLUP);
    pinMode(pin2, INPUT_PULLUP);
}

Switch_Position ThreewaySwitch::checkPosition() {
    if (digitalRead(pin1) == LOW) {
        position = UP;
    } else if (digitalRead(pin2) == LOW) {
        position = CENTER;
    } else {
        position = DOWN;
    }
    
    return position;
}
