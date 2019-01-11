
#pragma once

#include "Arduino.h"

class Drive
{
public:
  void init(uint8_t speed, uint8_t rotSpeed);
  void forward();
  void back();
  void ccw();
  void cw();
  void stop();
  void speed(uint8_t val);
  uint8_t speed() const;

private:
  void aktivateSpeed(uint8_t val);

  uint8_t _speed;
  uint8_t _rotSpeed;
};