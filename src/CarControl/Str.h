
#pragma once

#include "Arduino.h"

#define IS_DIGIT(c) (c >= '0' && c <= '9')

size_t tokenize(char *str, size_t maxTokenCount, char *tokens[]);

template <typename T>
T strToUint(const char *str)
{
  T val = T();

  while (IS_DIGIT(*str))
  {
    val = val * static_cast<T>(10) + static_cast<T>(*str++ - '0');
  }

  return val;
}