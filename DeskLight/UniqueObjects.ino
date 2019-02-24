#include "UniqueObjects.h"

ColorController::ColorController(LedPinOut ledPinOut) {
  pinOut = ledPinOut;
  redKnob = Potentiometer(pinOut.R);
  greenKnob = Potentiometer(pinOut.G);
  blueKnob = Potentiometer(pinOut.B);

  updateControls();

}

ColorController::~ColorController() {}

void ColorController::updateControls() {
  color.R = redKnob.getValue();
  color.G = greenKnob.getValue();
  color.B = blueKnob.getValue();
  color.W = 0;
}

Color ColorController::getColor() {
  return color;
}
