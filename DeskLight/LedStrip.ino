#include "LedStrip.h"

LedStrip::LedStrip(StripType stripType, LedPinOut ledPinOut) {
  type = stripType;
  pinOut = ledPinOut;
  color = Color(0,0,0,0,0);
}

Color LedStrip::getColor() {
  return color;
}

void LedStrip::setLedColor(Color newColor) {
  color = newColor;
}

void LedStrip::flashStrip() {
  switch (type) {
    case NA:
      break;

    case SMD_3528:
      analogWrite(pinOut.R, color.R);
      analogWrite(pinOut.G, color.G);
      analogWrite(pinOut.B, color.B);
      break;
  }
}
