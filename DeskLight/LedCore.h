#ifndef LED_CORE_H
#define LED_CORE_H

enum StripType{ NA, SMD_3528 };

struct Color {
  int R = 0;
  int G = 0;
  int B = 0;
  int W = 0;
} Color;

struct LedPinOut {
  int R = 0;
  int G = 0;
  int B = 0;
  int W = 0;
  int D = 0;
} LedPinOut;

#endif //LED_CORE_H
