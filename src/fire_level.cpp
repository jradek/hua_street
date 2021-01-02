#include "fire_level.h"

#include "util.h"


FireLevel::FireLevel(uint8_t pin)
  : m_pin(pin)
{
  _value = random(0, m_maxLevel);
  reset();
}

void FireLevel::reset()
{
  m_increment = random(m_minLevelIncrement, m_maxLevelIncrement + 1);

  if ((_value > m_maxLevel * 0.9) || ((_value < m_maxLevel * 0.1) && (random(100) < 50)))
  {
    m_increment = -m_increment;
  }

  _stepsLeft = random(m_minSteps, m_maxSteps + 1);
}

void FireLevel::update()
{
  int32_t value = _value;

  value += m_increment;

  if (value < 0)
  {
    value = 0;
    _stepsLeft = 0;
  }
  else if (value > m_maxLevel)
  {
    value = m_maxLevel;
    _stepsLeft = 0;
  }

  _value = value;

  if (_stepsLeft <= 0)
  {
    reset();
  }
  else
  {
    _stepsLeft--;
  }

  performOutput();
}

void FireLevel::performOutput() {
  uint8_t output = scaleValue(getNormalizedValue(), 1, 200);
  analogWrite(m_pin, m_isActive ? 50 + output : 0);
}

float FireLevel::getNormalizedValue()
{
  return (float)_value / (float)m_maxLevel;
}


