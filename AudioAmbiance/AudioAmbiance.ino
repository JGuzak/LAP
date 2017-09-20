
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
#include "Oscillator.h"

// Constants:
#define LED_STRIP_PIN 5
#define NUM_LEDS 60
#define BRIGHTNESS 70
float MAX_STEPS = 1020;
int QUARTER_STEPS = (int)(MAX_STEPS / 4);

// internal state variables
Switch_Position mode = UP, newMode = UP;
LEDColor color;
float stepSamples[NUM_LEDS];
float curStep = 0;
float stepAmt = 4.0;

// objects
ColorOscillator colorOscillator;
ThreewaySwitch threewaySwitch(7, 6);
Potentiometer knob1(A0), knob2(A1), knob3(A2);
AudioInput audioStream(A5);
Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(NUM_LEDS, LED_STRIP_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
    if (DEBUG_MODE) {
        Serial.begin(19200);
    }

    // init color and hardware states
    threewaySwitch.
    knob1.getValue();
    knob1.getValue();
    knob1.getValue();
    color.W = 100;
    color = setRGBColor(knob1, knob2, knob3, color);

    // temp mode switcher, don't use this
    // pinMode(4, OUTPUT);
    // pinMode(3, OUTPUT);
    // pinMode(2, OUTPUT);

    audioStream.setMaxRead(100);

    // init led strips
    ledStrip.setBrightness(BRIGHTNESS);
    ledStrip.begin();
    ledStrip.show();

    if (DEBUG_MODE) {
        Serial.println("Arduino Started");
    }
}

void loop() {

    // ***************************
    // temp old shitty way of switching modes, fix threeway switch class to handle this properly
    // if (digitalRead(13) == HIGH && mode == UP) {
    //     mode = CENTER;
    //     if (DEBUG_MODE) {
    //         Serial.println("switched to center mode");
    //     }
    //     delay(50);
    // } else if (digitalRead(13) == HIGH && mode == CENTER) {
    //     mode = DOWN;
    //     if (DEBUG_MODE) {
    //         Serial.println("switched to up mode");
    //     }
    //     delay(50);
    // } else if (digitalRead(13) == HIGH && mode == DOWN) {
    //     mode = UP;
    //     if (DEBUG_MODE) {
    //         Serial.println("switched to down mode");
    //     }
    //     delay(150);
    // }
    // ***************************

    // TODO: get this shit working
    newMode = threewaySwitch.getPosition();
    if (mode != newMode) {
        mode = newMode;
    }

    switch(mode) {
        case UP: // single color responsive mode
            // knob 1 sets red value
            // knob 2 sets green value
            // knob 3 sets blue value
            color = setRGBColor(knob1, knob2, knob3, color);
            color.W = 100;
            displayStaticStrip(&ledStrip, adjustBrightness(audioStream, color));

            // led outputs
            // digitalWrite(4, HIGH);
            // digitalWrite(3, LOW);
            // digitalWrite(2, LOW);
            break;
        case CENTER: // color oscillating responsive mode
            // knob 1 sets color osc speed
            // knob 2
            // knob 3
            colorOscillator.setStepAmount((float)knob1.getValue() / (float)knob1.MAX_OUTPUT);
            color = colorOscillator.updateColorCycle(color);
            displayStaticStrip(&ledStrip, adjustBrightness(audioStream, color));

            // led outputs
            // digitalWrite(4, LOW);
            // digitalWrite(3, HIGH);
            // digitalWrite(2, LOW);
            break;
        case DOWN: // color and brightness oscillating static mode
            // knob 1 sets color osc speed
            // knob 2 sets brightness osc speed
            // knob 3 sets brightness osc depth
            olorOscillator.setStepAmount((float)knob1.getValue() / (float)knob1.MAX_OUTPUT);
            color = colorOscillator.updateColorCycle(color);
            
            displayStaticStrip(&ledStrip, color);

            // led outputs
            // digitalWrite(4, LOW);
            // digitalWrite(3, LOW);
            // digitalWrite(2, HIGH);
            break;
    }

    if (DEBUG_MODE) {
        Serial.print("Current Mode: ");
        Serial.print(mode);
        Serial.print(" Knob 1: ");
        Serial.print(knob1.getValue());
        Serial.print(" Knob 2: ");
        Serial.print(knob2.getValue());
        Serial.print(" Knob 3: ");
        Serial.print(knob3.getValue());
        Serial.println();
    }
}
