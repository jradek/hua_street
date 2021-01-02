#include "const.hpp"

Const::Const(uint8_t pin)
    : m_pin(pin)
{}

void Const::update() {
    analogWrite(m_pin, m_isActive ? m_level : 0);
}
