
#pragma once

#include <Arduino.h>

size_t tokenize(char *str, size_t maxTokenCount, char *tokens[]);

template <typename T>
T strToUint(const char *str)
{
  T val = T();

  while (isDigit(*str))
  {
    val = val * static_cast<T>(10) + static_cast<T>(*str++ - '0');
  }

  return val;
}
