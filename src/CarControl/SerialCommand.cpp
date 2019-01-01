
#include "SerialCommand.h"

#include <assert.h>

#define LINE_BUFFER_SIZE 32

namespace
{

char lineBuffer[LINE_BUFFER_SIZE];

//TODO  readLineFromSerial
void readLineFromSerial(uint8_t bufLen, char *buf)
{
  assert(bufLen > 0);
  auto ptr = buf;

  while (1)
  {
    if (ptr - buf > bufLen - 1)
    {
      *(ptr - 1) = '\0';
      return;
    }

    auto c = Serial.read();
    switch (Serial.read())
    {
    case '\0':
    case '\r':
    case '\n':
      *ptr = '\0';
      return;

    default:
      *ptr++ = c;
      break;
    }
  }
}
} // namespace

SerialCommand::SerialCommand(uint8_t defsCount, CommandDef **defs)
    : _defsCount(defsCount), _defs(defs)
{
}

void SerialCommand::run()
{
  readLineFromSerial(LINE_BUFFER_SIZE, lineBuffer);

  for (auto i = 0; i < _defsCount; ++i)
  {
    if (strcmp(lineBuffer, _defs[i]->_name) == 0)
    {
      _defs[i]->_callback();
      break;
    }
  }
}
