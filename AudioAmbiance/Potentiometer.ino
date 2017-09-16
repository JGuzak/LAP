// Author: Jordan Guzak

#include "Potentiometer.h"

Potentiometer::Potentiometer(int a) {
  pin = a;
  value = analogRead(pin);
}

int Potentiometer::getValue() {
    int nextValue = map(analogRead(pin), 0, MAX_READ, 0, MAX_OUTPUT);
    if (nextValue >= value+2 || nextValue <= value-2) {
        value = nextValue;
    }
    return value;
}

