
#include "Str.h"

size_t tokenize(char *str, size_t maxTokenCount, char *tokens[])
{
  bool inToken = false;
  size_t tokenPos = 0;

  for (;;)
  {
    char c = *str;
    if (inToken)
    {
      switch (c)
      {
      case '\0':
        return tokenPos;

      case '\n':
      case '\r':
      case '\t':
      case ' ':
        inToken = false;
        *str = '\0';
        break;
      }
    }
    else
    {
      switch (c)
      {
      case '\0':
        return tokenPos;

      case '\n':
      case '\r':
      case '\t':
      case ' ':
        break;

      default:
        tokens[tokenPos++] = str;

        if (tokenPos >= maxTokenCount)
        {
          return tokenPos;
        }

        inToken = true;
        break;
      }
    }

    ++str;
  }
}

inline bool isDigit(char c)
{
  return c >= '0' && c <= '9';
}
