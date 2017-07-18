
#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer {
public:
  Potentiometer(int);

  void updateValue();
  int checkValue();
  
private:
  static int MAX_READ = 1024;
  int pin, value;
};

#endif
