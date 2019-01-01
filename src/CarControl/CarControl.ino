
#include "Drive.h"
#include "SerialCommand.h"

#define INIT_SPEED 150

const char *CMD_FORWARD = "forward";
const char *CMD_BACK = "back";
const char *CMD_LEFT = "left";
const char *CMD_RIGHT = "right";
const char *CMD_STOP = "stop";

Drive drive;

void forward();
void back();
void left();
void right();
void stop();

CommandDef commandDefs[] =
{
    {CMD_FORWARD, forward},
    {CMD_BACK, back},
    {CMD_LEFT, left},
    {CMD_RIGHT, right},
    {CMD_STOP, stop}
};

SerialCommand serialCommand(sizeof(commandDefs) / sizeof(CommandDef), commandDefs);

void setup()
{
  drive.init();
  drive.speed(INIT_SPEED);

  Serial.begin(9600);
}

void loop()
{
  serialCommand.run();
}

void forward()
{
  drive.forward();
  Serial.println(CMD_FORWARD);
}

void back()
{
  drive.back();
  Serial.println(CMD_BACK);
}

void left()
{
  drive.left();
  Serial.println(CMD_LEFT);
}

void right()
{
  drive.right();
  Serial.println(CMD_RIGHT);
}

void stop()
{
  drive.stop();
  Serial.println(CMD_STOP);
}