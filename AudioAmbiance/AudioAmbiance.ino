// Author: Jordan Guzak
// Audio Ambiance is designed to enhance your listening experience

//#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "ThreewaySwitch.h"
#include "Potentiometer.h"
#include "AudioInput.h"
#include "ColorModes.h"
#include "ColorOscillator.h"

// Constants:
#define LEFT_STRIP_PIN 10
#define RIGHT_STRIP_PIN 11
#define NUM_LEDS 60
#define BRIGHTNESS 70
float MAX_STEPS = 1020;
int QUARTER_STEPS = (int)(MAX_STEPS / 4);

// internal state variables
Switch_Position mode = CENTER;
LEDColor color;
float stepSamples[NUM_LEDS];
float curStep = 0;
float stepAmt = 4.0;

// objects
ColorOscillator colorOscillator;
ThreewaySwitch modeSwitch(3, 4, 5);
Potentiometer knob1(A0), knob2(A1), knob3(A2);
AudioInput audioStream(A5);
Adafruit_NeoPixel leftStrip = Adafruit_NeoPixel(NUM_LEDS, LEFT_STRIP_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel rightStrip = Adafruit_NeoPixel(NUM_LEDS, RIGHT_STRIP_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
    Serial.begin(19200);
    // set initial color and hardware reads
    knob1.getValue();
    knob1.getValue();
    knob1.getValue();
    color.W = 100;
    color = setRGBColor(knob1, knob2, knob3, color);

    // temp mode switcher
    pinMode(13, INPUT);

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
    if (digitalRead(13) == HIGH && mode == UP) {
        mode = CENTER;
        Serial.println("switched to center mode");
    } else if (digitalRead(13) == HIGH && mode == CENTER) {
        mode = UP;
        Serial.println("switched to up mode");
    }

    switch(mode) {
        case UP: // single color mode
            color = setRGBColor(knob1, knob2, knob3, color);
            displayStaticStrip(&rightStrip, adjustBrightness(audioStream, color));
            displayStaticStrip(&leftStrip, adjustBrightness(audioStream, color));
            break;
        case CENTER:
            colorOscillator.setStepAmount((float)knob1.getValue() / (float)knob1.MAX_OUTPUT);
            color = colorOscillator.updateColor(color);
            displayStaticStrip(&rightStrip, adjustBrightness(audioStream, color));
            displayStaticStrip(&leftStrip, adjustBrightness(audioStream, color));
            break;
    }
    
}
