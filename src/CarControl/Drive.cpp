
#include "Drive.h"

#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define ENA 6

void Drive::init(uint8_t speed, uint8_t rotSpeed)
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void Drive::forward()
{
  aktivateSpeed(_speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Drive::back()
{
  aktivateSpeed(_speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Drive::ccw()
{
  aktivateSpeed(_rotSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Drive::cw()
{
  aktivateSpeed(_rotSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Drive::stop()
{
  aktivateSpeed(0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Drive::aktivateSpeed(uint8_t val)
{
  analogWrite(ENB, val);
  analogWrite(ENA, val);
}

void Drive::speed(uint8_t val)
{
  _speed = val;
  aktivateSpeed(val);
}

uint8_t Drive::speed() const
{
  return _speed;
}