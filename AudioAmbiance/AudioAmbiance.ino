// Author: Jordan Guzak
// Audio Ambiance is designed to enhance your listening experience

#include <Adafruit_NeoPixel.h>
#include "ThreewaySwitch.h"
#include "Potentiometer.h"
#include "ColorModes.h"

// pin constants:
int leftStripPin = 10;
int rightStripPin = 11;
int numPixels = 60;

// internal state variables
Switch_Position curMode, checkMode;
int[] ledColor = [3];

// hardware objects
ThreewaySwitch modeSwitch(3, 4, 5);
Potentiometer knob1(A0), knob2(A1), knob3(A2);

Adafruit_NeoPixel leftStrip = Adafruit_NeoPixel(numPixels, leftStripPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel rightStrip = Adafruit_NeoPixel(numPixels, rightStripPin, NEO_GRB + NEO_KHZ800);

void setup() {
    // initial potentiometer and switch read
    curMode = modeSwitch.checkPosition();

    // clear led strips
    leftStrip.begin();
    rightStrip.begin();
    leftStrip.show();
    rightStrip.show();
}

void loop() {
    checkMode = modeSwitch.checkPosition();
    if (curMode != checkMode) {
        curMode = checkMode;
    }

    switch(curMode) {
    case UP:
        // mono mode
        
        break;
    case CENTER:
        // chroma mode
        
        break;
    case DOWN:
        // basic fft mode

        break;
    }

}
