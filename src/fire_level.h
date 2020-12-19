#ifndef FIRE_LEVEL_H
#define FIRE_LEVEL_H

#include <Arduino.h>

#include "effect.hpp"

class FireLevel : public Effect
{
public:
  FireLevel(uint8_t pin);

  void update();

  float getNormalizedValue();

private:
  void performOutput(); 

  uint8_t _pin;
  uint16_t _value;
  int16_t _direction;
  uint8_t _stepsLeft;

  void Reset();
};

#endif
