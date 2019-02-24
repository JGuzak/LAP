// Author: Jordan Guzak
// DeskLight is a modular reactive LED lighting solution for desks and rooms

#include "UniqueObjects.h"
#include "LedCore.h"
#include "LedStrip.h"

// LedPinOut primaryPinOut = LedPinOut {10, 11, 9, 0, 0};
// LedPinOut colorControllerPinOut = {A0, A1, A2, 0};

void setup() {
  Serial.begin(9600);
  LedStrip primaryStrip = LedStrip(SMD_3528, primaryPinOut);
  // ColorController colorController = ColorController(colorControllerPinOut);
}

void loop() {
  // primaryStrip.setColor(colorController.GetC)
  primaryStrip.flashStrip();
}
