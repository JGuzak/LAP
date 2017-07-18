
#include "Potentiometer.h"

Potentiometer::Potentiometer(int a) {
  pin = a;
  value = analogRead(pin);
}

int Potentiometer::checkValue() {
  return map(analogRead(pin), 0, MAX_READ, 0, 255);
}

