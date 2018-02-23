// Author: Jordan Guzak
// Audio Ambiance is designed to enhance your listening experience

bool DEBUG_MODE = true;

//#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <FFT.h>
#include "ThreewaySwitch.h"
#include "Potentiometer.h"
#include "AudioInput.h"
#include "ColorModes.h"
#include "Oscillator.h"
#include "ExtraFunctions.h"

#define LOG_OUT 1
#define FFT_N 256

// Constants:
const int LED_STRIP_PIN = 5;
const int  NUM_LEDS = 60;
const int  BRIGHTNESS = 80;
const int  NUM_MODES = 3;
const float MAX_STEPS = 1020.0;
const int QUARTER_STEPS = (int)(MAX_STEPS / 4);


// internal state variables
Switch_Position mode = UP, newMode = UP;
LEDColor color;
float stepSamples[NUM_LEDS];
float curStep = 0;
float stepAmt = 4.0;
float brightnessScale = 0.0;

// internal state objects
Oscillator colorOsc;
Oscillator brightnessOsc;

// hardware input objects
ThreewaySwitch threewaySwitch(6, 7);
Potentiometer knob1(A0), knob2(A1), knob3(A2);
AudioInput audioStream(A5);

// hardware output objects
int ledModePin[NUM_STATES] = { 11, 12, 13 };
Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(NUM_LEDS, LED_STRIP_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
    if (DEBUG_MODE) {
        Serial.begin(19200);
    }

    // init fft variables
    TIMSK0 = 0; // turn off timer0 for lower jitter
    ADCSRA = 0xe5; // set the adc to free running mode
    ADMUX = 0x40; // use adc0
    DIDR0 = 0x01; // turn off the digital input for adc0

    // init color and hardware states
    // threewaySwitch.getPosition();
    knob1.getValue();
    knob1.getValue();
    knob1.getValue();
    color.W = 100;
    color = setRGBColor(knob1, knob2, knob3, color);

    // led setup
    for (int i = 0; i < NUM_STATES; i++) {
        pinMode(ledModePin[i], OUTPUT);
    }

    // TODO: repackage this for later
    // led boot
    for (int i = 0; i < NUM_STATES; i++) {
        digitalWrite(ledModePin[i], HIGH);
        delay(100);
    }
    for (int i = 0; i < NUM_STATES; i++) {
        digitalWrite(ledModePin[i], LOW);
    }

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

    // TODO: get this shit working
    // newMode = threewaySwitch.getPosition();
    // if (mode != newMode) {
    //     mode = newMode;
    // }

    switch(mode) {
        case UP: // single color responsive mode
            // knob 1 sets red value
            // knob 2 sets green value
            // knob 3 sets blue value
            color = setRGBColor(knob1, knob2, knob3, color);
            color.W = 100;

            // audio stream sets brightness scale
            brightnessScale = getScale(audioStream);

            displayStaticStrip(&ledStrip, adjustBrightness(brightnessScale, color));

            // led outputs
            digitalWrite(ledModePin[0], HIGH);
            digitalWrite(ledModePin[1], LOW);
            digitalWrite(ledModePin[2], LOW);

            break;
        case CENTER: // color oscillating responsive mode
            // knob 1 sets color osc speed
            colorOsc.setStepAmt((float)knob1.getValue() / (float)knob1.MAX_OUTPUT);
            color = colorOsc.updateColorCycle(color);

            // TODO: setup features for knobs 2 and 3
            // knob 2 
            // knob 3 

            // audio stream sets brightness scale
            brightnessScale = getScale(audioStream);
            displayStaticStrip(&ledStrip, adjustBrightness(brightnessScale, color));

            // led outputs
            digitalWrite(ledModePin[0], LOW);
            digitalWrite(ledModePin[1], HIGH);
            digitalWrite(ledModePin[2], LOW);
            break;
        case DOWN: // color and brightness oscillating static mode
            // knob 1 sets color osc speed
            colorOsc.setStepAmt(getScale(knob1));
            color = colorOsc.updateColorCycle(color);

            // knob 2 sets brightness osc speed
            brightnessOsc.setStepAmt(mapFloat(getScale(knob2), 0.0, 1.0, 0.3, 1.0));

            // knob 3 sets brightness osc depth
            float maxBrightness = getScale(knob3);

            // audio stream sets brightness scale
            brightnessScale = mapFloat(brightnessOsc.getCurPos(), -1.0, 1.0, 0.0, maxBrightness);
            displayStaticStrip(&ledStrip, adjustBrightness(brightnessScale, color));

            // led outputs
            digitalWrite(ledModePin[0], LOW);
            digitalWrite(ledModePin[1], LOW);
            digitalWrite(ledModePin[2], HIGH);
            break;
    }

    if (DEBUG_MODE) {
        Serial.print("Mode: ");
        Serial.print(mode+1);
        Serial.print(" |Knob 1: ");
        Serial.print(knob1.getValue());
        Serial.print(" |Knob 2: ");
        Serial.print(knob2.getValue());
        Serial.print(" |Knob 3: ");
        Serial.print(knob3.getValue());
        Serial.println();
    }
}
