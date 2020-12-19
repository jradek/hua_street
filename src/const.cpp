#include "const.hpp"

Const::Const(uint8_t pin, uint8_t level)
    : m_pin(pin)
    , m_level(level)
{}

void Const::update() {
    analogWrite(m_pin, m_level);
}
