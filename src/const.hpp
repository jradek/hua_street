#ifndef CONST_H
#define CONST_H

#include <Arduino.h>

#include "effect.hpp"

class Const : public Effect {
public:
    explicit Const(uint8_t pin);

    inline Const& setLevel(uint8_t lvl) {
        m_level = lvl;
        return *this;
    }

    inline void setup() {
        pinMode(m_pin, OUTPUT);
    }


    void update();

private:
    uint8_t m_pin;
    uint8_t m_level = 100;
};

#endif
