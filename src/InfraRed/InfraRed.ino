
#include "IRremote.h"

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

#define RECV_PIN 12

#define FORWARD 16736925
#define BACK 16754775
#define LEFT 16720605
#define RIGHT 16761405
#define STOP 16712445

#define INIT_SPEED 100

class Drive
{
public:
  Drive()
  {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
  }

  void forward()
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  void back()
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  void left()
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  void right()
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  void stop()
  {
    setSpeed(0);
  }

  void setSpeed(int speed)
  {
    analogWrite(ENB, speed);
    analogWrite(ENA, speed);
  }
};

Drive drive;
IRrecv irrecv(RECV_PIN);

void setup()
{
  irrecv.enableIRIn();
}

decode_results results;
unsigned long val;
unsigned long preMillis;

void loop()
{
  drive.setSpeed(INIT_SPEED);

  if (irrecv.decode(&results))
  {
    preMillis = millis();
    val = results.value;
    irrecv.resume();
    switch (val)
    {
    case FORWARD:
      drive.forward();
      break;
    case BACK:
      drive.back();
      break;
    case LEFT:
      drive.left();
      break;
    case RIGHT:
      drive.right();
      break;
    default:
      drive.stop();
      break;
    }
  }
  else
  {
    if (millis() - preMillis > 500)
    {
      drive.stop();
      preMillis = millis();
    }
  }
}
