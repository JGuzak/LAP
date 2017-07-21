// Author: Jordan Guzak
// Audio Ambiance is designed to enhance your listening experience

#include <Adafruit_NeoPixel.h>
#include "ThreewaySwitch.h"
#include "Potentiometer.h"
#include "ColorModes.h"

// TODO:
//  []  run tests on modifying incoming audio volume pre analog read 
//          (adjust analog signal) vs post analog read (digital scaling).
//  []  design and implement analogReadToColor()


// pin constants:
int leftStripPin = 10;
int rightStripPin = 11;
int numPixels = 60;

// internal state variables
Switch_Position curMode, checkMode;
// array holds:
//  0: green
//  1: red
//  2: blue
//  3: white (brightness)
int[] ledColor = [0, 0, 0, 0];

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
