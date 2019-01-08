
#pragma once

#include "Arduino.h"

class Drive
{
public:
  void init(uint8_t initSpeed);
  void forward();
  void back();
  void ccw();
  void cw();
  void stop();
  void speed(uint8_t speed);
  uint8_t speed() const;

private:
  uint8_t _speed;
};