
#include "SerialCommand.h"
#include "Str.h"

#define LINE_BUFFER_SIZE 32
#define ARGUMENT_SIZE 4

namespace
{

char lineBuffer[LINE_BUFFER_SIZE];
char *arguments[ARGUMENT_SIZE];

void readLineFromSerial(ptrdiff_t bufLen, char *buf)
{
  auto ptr = buf;

  while (1)
  {
    if (Serial.available() > 0)
    {
      auto c = Serial.read();
      switch (c)
      {
      case '\0':
      case '\n':
        *ptr = '\0';
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
  size_t argumentCount = tokenize(lineBuffer, ARGUMENT_SIZE, arguments);

  if (argumentCount > 0)
  {
    for (size_t i = 0; i < _defsCount; ++i)
    {
      if (strcmp(arguments[0], _defs[i]._name) == 0)
      {
        _defs[i]._callback(argumentCount, arguments);
        break;
      }
    }
  }
}
