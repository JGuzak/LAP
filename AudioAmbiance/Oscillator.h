// Author: Jordan Guzak

#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator {
public:
    Oscillator();
    ~Oscillator() = default;

    void setOscSpeed(float);
    void updatePosition();
    float getCurrentPosition();

private:
    float position;

}

#endif // !COLOR_OSCILLATOR_H