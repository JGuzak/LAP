// Author: Jordan Guzak

#ifndef AUDIO_INPUT_H
#define AUDIO_INPUT_H

class AudioInput {
public:
  AudioInput(int);

  int getValue();
  void setMaxRead(int);

  static const int MAX_UPPER_READ_THRESHOLD = 150, MIN_UPPER_READ_THRESHOLD = 20;
  static const int MAX_UPPER_OUTPUT = 230, MIN_READ = 5;
  static const int BUFFER_SIZE = 16;
  int upperReadThreshold;
private:
  int pin, value;
};

#endif
