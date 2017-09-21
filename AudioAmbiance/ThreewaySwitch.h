// Author: Jordan Guzak

#ifndef THREEWAY_SWITCH_H
#define THREEWAY_SWITCH_H

const static int NUM_STATES = 3;
const static int STATE[NUM_STATES][NUM_STATES] = {
    { 0, 0, 1 },
    { 0, 1, 0 },
    { 1, 0, 0 }
};
enum Switch_Position{ UP, CENTER, DOWN };

class ThreewaySwitch {
public:
    ThreewaySwitch(int, int);
    Switch_Position getPosition();
    int* getState();

private:
    void updateState();
    int state[3];
    int pin1, pin2;
    Switch_Position position;
};

#endif
