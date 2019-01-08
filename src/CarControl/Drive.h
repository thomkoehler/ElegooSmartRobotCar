
#pragma once

#include "Arduino.h"

class Drive
{
public:
  void init();
  void forward();
  void back();
  void ccw();
  void cw();
  void stop();
  void speed(uint8_t speed);
};