// Author: Jordan Guzak

#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer {
public:
  Potentiometer() = delete;
  Potentiometer(int);
  ~Potentiometer();

  int getValue();

  static const int MAX_READ = 700;
  static const int MAX_OUTPUT = 235;
private:
  int pin, value;
};

#endif
