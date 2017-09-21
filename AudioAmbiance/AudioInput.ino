// Author: Jordan Guzak

#include "AudioInput.h"

AudioInput::AudioInput(int p) {
    upperReadThreshold = 80;
    pin = p;
    value = analogRead(pin);
}

/* 
 *  Read in a buffer of samples and get the average of the incoming signal
 *  across the buffer. Then check the average to make sure it stays in the
 *  proper range.
*/ 
int AudioInput::getValue() {
    int avgValue = 0;
    avgValue = analogRead(pin);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        avgValue += analogRead(pin);
        delay(2);
    }
    avgValue = avgValue / BUFFER_SIZE;

    if (avgValue > upperReadThreshold) {
        avgValue = upperReadThreshold;
    }
    else if (avgValue < MIN_READ) {
        avgValue = MIN_READ;
    }

    int scaledValue = map(avgValue, MIN_READ, upperReadThreshold, 0, MAX_UPPER_OUTPUT);
    if (scaledValue < 0) {
        value = 0;
    } else {
        value = scaledValue;
    }
    
    return value;
}
/*
 * Sets the maximum reading threshold to normalize incoming audio.
 * Argument must be between 20 and 150.
 */
void AudioInput::setMaxRead(int newMax) {
    if (newMax > MIN_UPPER_READ_THRESHOLD && newMax < MAX_UPPER_READ_THRESHOLD) {
        upperReadThreshold = newMax;
    }
}

