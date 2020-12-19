#ifndef UTIL_H
#define UTIL_H

#include <Arduino.h>

inline uint8_t scaleValue(float normalizedValue, uint8_t min, uint8_t max)
{
  int16_t scaled = normalizedValue * (max - min + 1) + min;
  if (scaled > 255)
  {
    return 255;
  }

  if (scaled < 0)
  {
    return 0;
  }

  return scaled;
}

#endif