
#pragma once

#include "Arduino.h"

class SerialCommand;

struct CommandDef
{
  const char *_name;
  void (*_callback)();
};

class SerialCommand
{
public:
  SerialCommand(uint8_t defsCount, CommandDef *defs[]);
  void run();

private:
  uint8_t _defsCount;
  CommandDef *_defs[];
};