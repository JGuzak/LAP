// Author: Jordan Guzak

void singleColorDynamicBrightness(Adafruit_Neopixel strip, int numPixels, int[] color) {
    for (int i = 0; i < numPixels; i++) {
        strip.setPixelColor(i, color[0], color[1], color[2], color[3]);
    }
    strip.show();
}
