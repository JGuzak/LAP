// Author: Jordan Guzak

#include "ThreewaySwitch.h"

ThreewaySwitch::ThreewaySwitch(int a, int b, int c) {
    pin1 = a;
    pin2 = b;
    pin3 = c;

    pinMode(pin1, INPUT);
    pinMode(pin2, INPUT);
    pinMode(pin3, INPUT);
}

Switch_Position ThreewaySwitch::checkPosition() {
    if (digitalRead(pin1)) {
        position = UP;
    } else if (digitalRead(pin2)) {
        position = CENTER;
    } else if (digitalRead(pin3)) {
        position = DOWN;
    }
    
    return position;
}
