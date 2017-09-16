
// Author: Jordan Guzak
// Audio Ambiance is designed to enhance your listening experience

bool DEBUG_MODE = true;

//#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "ThreewaySwitch.h"
#include "Potentiometer.h"
#include "AudioInput.h"
#include "ColorModes.h"
#include "ColorOscillator.h"

// Constants:
#define LED_STRIP_PIN 5
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
ThreewaySwitch modeSwitch(3, 4);
Potentiometer knob1(A0), knob2(A1), knob3(A2);
AudioInput audioStream(A5);
Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(NUM_LEDS, LED_STRIP_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
    if (DEBUG_MODE) {
        Serial.begin(19200);
    }
    // set initial color and hardware reads
    knob1.getValue();
    knob1.getValue();
    knob1.getValue();
    color.W = 100;
    color = setRGBColor(knob1, knob2, knob3, color);

    // temp mode switcher
    pinMode(13, INPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);

    audioStream.setMaxRead(100);

    // clear led strips
    ledStrip.setBrightness(BRIGHTNESS);
    ledStrip.begin();
    ledStrip.show();
    Serial.println("Arduino Started");
}

void loop() {
    if (digitalRead(13) == HIGH && mode == UP) {
        mode = CENTER;
        if (DEBUG_MODE) {
            Serial.println("switched to center mode");
        }
        delay(50);
    } else if (digitalRead(13) == HIGH && mode == CENTER) {
        mode = DOWN;
        if (DEBUG_MODE) {
            Serial.println("switched to up mode");
        }
        delay(50);
    } else if (digitalRead(13) == HIGH && mode == DOWN) {
        mode = UP;
        if (DEBUG_MODE) {
            Serial.println("switched to down mode");
        }
        delay(150);
    }

    switch(mode) {
        case UP: // single color mode
            digitalWrite(7, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(5, LOW);
            color = setRGBColor(knob1, knob2, knob3, color);
            displayStaticStrip(&ledStrip, adjustBrightness(audioStream, color));
            break;
        case CENTER:
            digitalWrite(7, LOW);
            digitalWrite(6, HIGH);
            digitalWrite(5, LOW);
            colorOscillator.setStepAmount((float)knob1.getValue() / (float)knob1.MAX_OUTPUT);
            color = colorOscillator.updateColor(color);
            displayStaticStrip(&ledStrip, adjustBrightness(audioStream, color));
            break;
        case DOWN:
            digitalWrite(7, LOW);
            digitalWrite(6, LOW);
            digitalWrite(5, HIGH);
            color = setRGBColor(knob1, knob2, knob3, color);
            displayStaticStrip(&ledStrip, color);
            break;
    }
}
