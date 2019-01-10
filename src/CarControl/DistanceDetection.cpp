
#include <Arduino.h>

#include "DistanceDetection.h"

#define SERVO_PIN 3

const int ECHO = A4;
const int TRIG = A5;

void DistanceDetection::init()
{
  _servo.attach(SERVO_PIN);

  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void DistanceDetection::servoPosition(int value)
{
  _servo.write(value);
}

int DistanceDetection::servoPosition()
{
  return _servo.read();
}

int DistanceDetection::distance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  return (int)pulseIn(ECHO, HIGH) / 58;
}