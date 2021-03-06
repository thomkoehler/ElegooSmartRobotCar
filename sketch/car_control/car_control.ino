
#include "Drive.h"
#include "DistanceDetection.h"
#include "SerialCommand.h"
#include "Str.h"

const uint8_t INIT_SPEED = 150;
const uint8_t INIT_ROT_SPEED = 150;

const char *CMD_FORWARD = "fw";
const char *CMD_BACKWARD = "bw";
const char *CMD_CCW = "ccw";
const char *CMD_CW = "cw";
const char *CMD_STOP = "st";
const char *CMD_SET_SPEED = "ss";
const char *CMD_GET_SPEED = "gs";
const char *CMD_SET_DIST_POS = "sdp";
const char *CMD_GET_DIST_POS = "gdp";
const char *CMD_GET_DIST = "gd";

Drive drive;
DistanceDetection distanceDetection;

void forward(int argc, char *argv[]);
void backward(int argc, char *argv[]);
void ccw(int argc, char *argv[]);
void cw(int argc, char *argv[]);
void stop(int argc, char *argv[]);
void setSpeed(int argc, char *argv[]);
void getSpeed(int argc, char *argv[]);
void setDistPos(int argc, char *argv[]);
void getDistPos(int argc, char *argv[]);
void getDist(int argc, char *argv[]);

CommandDef commandDefs[] =
{
    {CMD_FORWARD, forward},
    {CMD_BACKWARD, backward},
    {CMD_CCW, ccw},
    {CMD_CW, cw},
    {CMD_STOP, stop},
    {CMD_SET_SPEED, setSpeed},
    {CMD_GET_SPEED, getSpeed},
    {CMD_SET_DIST_POS, setDistPos},
    {CMD_GET_DIST_POS, getDistPos},
    {CMD_GET_DIST, getDist},
};

SerialCommand serialCommand(sizeof(commandDefs) / sizeof(CommandDef), commandDefs);

void setup()
{
  drive.init(INIT_SPEED, INIT_ROT_SPEED);
  distanceDetection.init();
  Serial.begin(9600);
}

void loop()
{
  serialCommand.run();
}

void forward(int, char *[])
{
  drive.forward();
  Serial.println(CMD_FORWARD);
}

void backward(int, char *[])
{
  drive.back();
  Serial.println(CMD_BACKWARD);
}

void ccw(int, char *[])
{
  drive.ccw();
  Serial.println(CMD_CCW);
}

void cw(int, char *[])
{
  drive.cw();
  Serial.println(CMD_CW);
}

void stop(int, char *[])
{
  drive.stop();
  Serial.println(CMD_STOP);
}

void setSpeed(int argc, char *argv[])
{
  if (argc > 1)
  {
    drive.speed(strToUint<uint8_t>(argv[1]));
    Serial.println(CMD_SET_SPEED);
  }
}

void getSpeed(int, char *[])
{
  Serial.print("sp: ");
  Serial.println(drive.speed(), DEC);
}

void setDistPos(int argc, char *argv[])
{
  if (argc > 1)
  {
    distanceDetection.servoPosition(strToUint<int>(argv[1]));
  }
}

void getDistPos(int, char *[])
{
  Serial.print("dp: ");
  Serial.println(distanceDetection.servoPosition(), DEC);
}

void getDist(int, char *[])
{
  Serial.print("d: ");
  Serial.println(distanceDetection.distance(), DEC);
}