// Author: Jordan Guzak

#ifndef THREEWAY_SWITCH_H
#define THREEWAY_SWITCH_H

enum Switch_Position{ UP, CENTER, DOWN };

class ThreewaySwitch {

public:
    ThreewaySwitch(int, int);
    Switch_Position getPosition();
    int[] getState();

private:
    void updateState();
    int state[3];
    Switch_Position position;

};

#endif
