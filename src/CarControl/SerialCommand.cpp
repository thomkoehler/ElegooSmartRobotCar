
#include "SerialCommand.h"

#include <assert.h>

#define LINE_BUFFER_SIZE 32

namespace
{

char lineBuffer[LINE_BUFFER_SIZE];

void readLineFromSerial(ptrdiff_t bufLen, char *buf)
{
  auto ptr = buf;

  while (1)
  {
    if (Serial.available() > 0)
    {
      auto c = Serial.read();
      switch (Serial.read())
      {
      case '\0':
      case '\r':
      case '\n':
        *ptr = '\0';
        Serial.println(ptr);
        return;

      default:
        *ptr++ = c;
        break;
      }

      if (ptr - buf > bufLen - 1)
      {
        *(ptr - 1) = '\0';
        return;
      }
    }
  }
}
} // namespace

SerialCommand::SerialCommand(size_t defsCount, CommandDef *defs)
    : _defsCount(defsCount), _defs(defs)
{
}

void SerialCommand::run()
{
  readLineFromSerial(LINE_BUFFER_SIZE, lineBuffer);

  for (size_t i = 0; i < _defsCount; ++i)
  {
    if (strcmp(lineBuffer, _defs[i]._name) == 0)
    {
      _defs[i]._callback();
      break;
    }
  }
}
