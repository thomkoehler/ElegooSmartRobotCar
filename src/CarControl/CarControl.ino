
#include "IRremote.h"
#include "Drive.h"

#define RECV_PIN 12

#define FORWARD 16736925
#define BACK 16754775
#define LEFT 16720605
#define RIGHT 16761405
#define STOP 16712445

#define INIT_SPEED 150

Drive drive;
IRrecv irrecv(RECV_PIN);

void setup()
{
  drive.init();
  drive.speed(INIT_SPEED);

  irrecv.enableIRIn();
}

decode_results results;

void loop()
{
  if (irrecv.decode(&results))
  {
    irrecv.resume();
    switch (results.value)
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

    case STOP:
      drive.stop();
      break;
    }
  }
}
