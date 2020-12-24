#ifndef FIRE_LEVEL_H
#define FIRE_LEVEL_H

#include <Arduino.h>

#include "effect.hpp"

class FireLevel : public Effect
{
public:
  explicit FireLevel(uint8_t pin);

  inline void setup() {
      pinMode(m_pin, OUTPUT);
  }

  inline FireLevel& setMaxLevel(uint16_t lvl = 65535) {
    m_maxLevel = lvl;
    return *this;
  }

  inline FireLevel& setIncrement(uint16_t minInc = 500, uint16_t maxInc = 5000) {
    m_minLevelIncrement = minInc;
    m_maxLevelIncrement = maxInc;
    return *this;
  }

  inline FireLevel& setSteps(uint8_t minSteps = 10, uint8_t maxSteps = 30) {
    m_minSteps = minSteps;
    m_maxSteps = maxSteps;
    return *this;
  }

  void update();

  float getNormalizedValue();

private:
  void performOutput(); 

  uint8_t m_pin;

  uint16_t m_maxLevel = 65535;
  uint16_t m_minLevelIncrement = 500;
  uint16_t m_maxLevelIncrement = 5000;
  uint8_t m_minSteps = 10;
  uint8_t m_maxSteps = 30;

  uint16_t _value;
  int16_t m_increment;
  uint8_t _stepsLeft;

  void reset();
};

#endif
