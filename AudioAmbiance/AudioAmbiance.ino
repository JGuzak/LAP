// Author: Jordan Guzak
// Audio Ambiance is designed to enhance your listening experience

#include "ThreewaySwitch.h"
#include "Potentiometer.h"

Switch_Position curMode, checkMode;
ThreewaySwitch modeSwitch(3, 4, 5);

Potentiometer pot1(A0), pot2(A1), pot3(A2);

void setup() {
  // initial potentiometer and switch read
  curMode = modeSwitch.checkPosition();
}

void loop() {
  checkMode = modeSwitch.checkPosition();
  if (curMode != checkMode) {
    curMode = checkMode;
  }

  switch(curMode) {
    case UP:
      break;
    case CENTER:
      break;
    case DOWN:
      break;
    
  }

}
