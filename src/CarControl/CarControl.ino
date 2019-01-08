
#include "Drive.h"
#include "SerialCommand.h"
#include "Str.h"

#define INIT_SPEED 150

const char *CMD_FORWARD = "fw";
const char *CMD_BACKWARD = "bw";
const char *CMD_CCW = "ccw";
const char *CMD_CW = "cw";
const char *CMD_STOP = "st";
const char *CMD_SET_SPEED = "ss";

Drive drive;

void forward(int argc, char *argv[]);
void backward(int argc, char *argv[]);
void ccw(int argc, char *argv[]);
void cw(int argc, char *argv[]);
void stop(int argc, char *argv[]);
void setSpeed(int argc, char *argv[]);

CommandDef commandDefs[] =
{
    {CMD_FORWARD, forward},
    {CMD_BACKWARD, backward},
    {CMD_CCW, ccw},
    {CMD_CW, cw},
    {CMD_STOP, stop},
    {CMD_SET_SPEED, setSpeed},
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

void forward(int argc, char *argv[])
{
  drive.forward();
  Serial.println(CMD_FORWARD);
}

void backward(int argc, char *argv[])
{
  drive.back();
  Serial.println(CMD_BACKWARD);
}

void ccw(int argc, char *argv[])
{
  drive.ccw();
  Serial.println(CMD_CCW);
}

void cw(int argc, char *argv[])
{
  drive.cw();
  Serial.println(CMD_CW);
}

void stop(int argc, char *argv[])
{
  drive.stop();
  Serial.println(CMD_STOP);
}

void setSpeed(int argc, char *argv[])
{
  if (argc > 1)
  {
    drive.speed(strToUint<uint8_t>(argv[1]));
  }
}