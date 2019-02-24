// Author: Jordan Guzak

#include "LedCore.h"

#ifndef LED_STRIP_H
#define LED_STRIP_H

class LedStrip {
public:
  LedStrip() = delete;
  LedStrip(StripType, LedPinOut);
  ~LedStrip();

  Color getColor();
  void setLedColor(Color);

  void flashStrip();

private:
  StripType type;
  LedPinOut pinOut;
  Color color;
  int stripLength;
};

#endif // LED_STRIP_H
