// Author: Jordan Guzak

void singleColorDynamicBrightness(Adafruit_Neopixel strip, int numPixels, int volume, int[] color) {
    strip.setBrightness(map(volume, 0, 1024, 0, 255));
    for (int i = 0; i < numPixels; i++) {
        strip.setPixelColor(i, color[0], color[1], color[2]);
    }
    strip.show();
}
