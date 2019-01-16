
#pragma once

#include <Servo.h>

class DistanceDetection
{
public:
  void init();
  void servoPosition(int value);
  int servoPosition();
  int distance();

private:
  Servo _servo;
};