#ifndef CONST_H
#define CONST_H

#include <Arduino.h>

#include "effect.hpp"

class Const {
public:
    Const(uint8_t pin, uint8_t level);

    void update();

private:
    uint8_t m_pin;
    uint8_t m_level;
};

#endif
