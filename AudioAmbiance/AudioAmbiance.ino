// Author: Jordan Guzak
// Audio Ambiance is designed to enhance your listening experience

//#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "ThreewaySwitch.h"
#include "Potentiometer.h"
#include "AudioInput.h"
#include "ColorModes.h"

// TODO:
//  []  run tests on modifying incoming audio volume pre analog read 
//          (adjust analog signal) vs post analog read (digital scaling).
//  []  design and implement analogReadToColor()

// Constants:
#define LEFT_STRIP_PIN 10
#define RIGHT_STRIP_PIN 11
#define NUM_LEDS 60
#define BRIGHTNESS 70

// internal state variables
Switch_Position mode = UP;
LEDColor color;
float stepSamples[NUM_LEDS];
int curStep = 0;

// hardware objects
ThreewaySwitch modeSwitch(3, 4, 5);
Potentiometer knob1(A0), knob2(A1), knob3(A2);
AudioInput audioStream(A5);
Adafruit_NeoPixel leftStrip = Adafruit_NeoPixel(NUM_LEDS, LEFT_STRIP_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel rightStrip = Adafruit_NeoPixel(NUM_LEDS, RIGHT_STRIP_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
    Serial.begin(9600);
    // set initial color and hardware reads
    knob1.getValue();
    knob1.getValue();
    knob1.getValue();
    color.W = 100;
    color = setRGBColor(knob1, knob2, knob3, color);

    audioStream.setMaxRead(100);

    // clear led strips
    rightStrip.setBrightness(BRIGHTNESS);
    rightStrip.begin();
    rightStrip.show();
    leftStrip.setBrightness(BRIGHTNESS);
    leftStrip.begin();
    leftStrip.show();
}

void loop() {
    switch(mode) {
        case UP: // single color mode
            color = setRGBColor(knob1, knob2, knob3, color);
            displayStaticStrip(&leftStrip, adjustBrightness(audioStream, color));
            break;
        case CENTER:
//            color = setRGBColor(knob1, knob2, knob3, color);
//            if (curStep > NUM_LEDS) {
//                curStep = 0;
//            }
//            else {
//                curStep++;
//            }
//
//            stepSamples[curStep] = getVolumeScale(audioStream);
//            Serial.println(stepSamples[curStep]);
//            displayDynamicStrip(&leftStrip, stepSamples, color);
//            
            break;
    }
    
}
