// Author: Jordan Guzak

#ifndef THREEWAY_SWITCH_H
#define THREEWAY_SWITCH_H

enum Switch_Position{ UP, CENTER, DOWN };

class ThreewaySwitch {

public:
    ThreewaySwitch(int, int);
    Switch_Position checkPosition();

private:
    int pin1, pin2, pin3;
    Switch_Position position;

};

#endif
