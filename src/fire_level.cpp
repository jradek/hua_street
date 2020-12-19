#include "fire_level.h"

#include "util.h"

#define FIRE_MAX_LEVEL_VALUE 65535
#define FIRE_MIN_LEVEL_DIR 500
#define FIRE_MAX_LEVEL_DIR 5000
#define FIRE_MIN_LEVEL_STEPS 10
#define FIRE_MAX_LEVEL_STEPS 30

FireLevel::FireLevel(uint8_t pin)
  : _pin(pin)
{
  _value = random(0, 65536);
  Reset();
}

void FireLevel::Reset()
{
  _direction = random(FIRE_MIN_LEVEL_DIR, FIRE_MAX_LEVEL_DIR + 1);

  if ((_value > FIRE_MAX_LEVEL_VALUE * 0.9) || ((_value > FIRE_MAX_LEVEL_VALUE * 0.1) && (random(100) < 50)))
  {
    _direction = -_direction;
  }

  _stepsLeft = random(FIRE_MIN_LEVEL_STEPS, FIRE_MAX_LEVEL_STEPS + 1);
}

void FireLevel::update()
{
  int32_t value = _value;

  value += _direction;

  if (value < 0)
  {
    value = 0;
    _stepsLeft = 0;
  }
  else if (value > FIRE_MAX_LEVEL_VALUE)
  {
    value = FIRE_MAX_LEVEL_VALUE;
    _stepsLeft = 0;
  }

  _value = value;

  if (_stepsLeft <= 0)
  {
    Reset();
  }
  else
  {
    _stepsLeft--;
  }

  performOutput();
}

void FireLevel::performOutput() {
  uint8_t output = scaleValue(getNormalizedValue(), 1, 200);
  analogWrite(_pin, 50 + output);
}

float FireLevel::getNormalizedValue()
{
  return (float)_value / FIRE_MAX_LEVEL_VALUE;
}


