// Author: Jordan Guzak
#include <Adafruit_NeoPixel.h>

// array holds:
//  0: green
//  1: red
//  2: blue
//  3: white (brightness)
struct LEDColor
{
    int G = 0;
    int R = 0;
    int B = 0;
    int W = 0;
};

inline LEDColor setColorFromSinglePotentiometer(Potentiometer& knob, LEDColor color) {

    return color;
}

inline LEDColor setRGBColor(Potentiometer& knob1, Potentiometer& knob2, Potentiometer& knob3, LEDColor color) {
    color.G = map(knob1.getValue(), 0, knob1.MAX_OUTPUT, 0, 255);
    color.R = map(knob2.getValue(), 0, knob2.MAX_OUTPUT, 0, 255);
    color.B = map(knob3.getValue(), 0, knob3.MAX_OUTPUT, 0, 255);

    return color;
}

inline float getVolumeScale(AudioInput& audio) {
    float scale = (float)audio.getValue() / (float)audio.MAX_UPPER_OUTPUT;

    if (scale > 1.0) {
        scale = 1.0;
    }

    return scale;
}

inline float getVolumeScale(Potentiometer& knob) {
    float scale = (float)knob.getValue() / (float)knob.MAX_OUTPUT;

    if (scale > 1.0) {
        scale = 1.0;
    }

    return scale;
}

inline LEDColor adjustBrightness(AudioInput& audio, LEDColor color) {
    float scale = getVolumeScale(audio);

    color.G = color.G * scale;
    color.R = color.R * scale;
    color.B = color.B * scale;
    color.W = color.W * scale;

    return color;
}

inline LEDColor adjustBrightness(Potentiometer& knob, LEDColor color) {
    float scale = getVolumeScale(knob);

    color.G = color.G * scale;
    color.R = color.R * scale;
    color.B = color.B * scale;
    color.W = color.W * scale;

    return color;
}

inline void displayStaticStrip(Adafruit_NeoPixel* strip, LEDColor color) {
    for (uint16_t i = 0; i < strip->numPixels(); i++) {
        strip->setPixelColor(i, strip->Color(byte(color.G), byte(color.R), byte(color.B), byte(color.W)));
    }
    delay(1);
    strip->show();
}

inline void displayDynamicStrip(Adafruit_NeoPixel* strip, float step[], LEDColor color) {
    int node = 0;
    for (uint16_t i = 0; i < strip->numPixels(); i++) {
        strip->setPixelColor(i, strip->Color(byte(color.G * step[node]), byte(color.R * step[node]), byte(color.B * step[node]), byte(color.W * step[node])));
        node++;
    }
    delay(1);
    strip->show();
}
