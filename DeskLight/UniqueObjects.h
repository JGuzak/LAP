// Author: Jordan Guzak

#include "Potentiometer.h"
#include "LedCore.h"
#include "LedStrip.h"

#ifndef UNIQUE_OBJECTS_H
#define UNIQUE_OBJECTS_H

class ColorController {
public:
  ColorController() = delete;
  ColorController(LedPinOut);
  ~ColorController();

  void updateControls();
  Color getColor();

private:
  LedPinOut pinOut;
  Color color;
  Potentiometer redKnob;
  Potentiometer greenKnob;
  Potentiometer blueKnob;
};

#endif // UNIQUE_OBJECTS_H
