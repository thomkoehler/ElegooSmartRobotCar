
#include "Drive.h"
#include "SerialCommand.h"

#define INIT_SPEED 150

Drive drive;

CommandDef commandDefs[] =
{
    {"f", []() { drive.forward(); }},
    {"b", []() { drive.back(); }},
    {"l", []() { drive.left(); }},
    {"f", []() { drive.right(); }},
    {"s", []() { drive.stop(); }}
};

SerialCommand serialCommand(sizeof(commandDefs) / sizeof(CommandDef), commandDefs);

void setup()
{
  drive.init();
  drive.speed(INIT_SPEED);
}

void loop()
{
  serialCommand.run();
}
