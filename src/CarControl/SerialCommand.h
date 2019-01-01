
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
  SerialCommand(size_t defsCount, CommandDef *defs);
  void run();

private:
  size_t _defsCount;
  CommandDef *_defs;
};