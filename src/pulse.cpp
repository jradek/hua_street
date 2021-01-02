#include "pulse.hpp"

 Pulse::Pulse(uint8_t pin)
    : m_pin(pin)
    , m_t(millis())
{}

void Pulse::update() {
    unsigned long now = millis();

    if (now < m_sleepUtil) {
        analogWrite(m_pin, m_isActive ? m_minLevel : 0);
        return;
    } else {
        if (m_calcNewValues) {
            m_pulseCount = random(m_minPulses, m_maxPulses) + 1;
            // Serial.printf("Pulse count %d\n", m_pulseCount);
            m_calcNewValues = false;
        }
    }

    float pulseHalf = m_pulseLengthMSec / 2;
    float scale = 0;

    if (now > (m_t + m_pulseLengthMSec + m_pulsePauseMSec)) {
        // end cycle
        m_t = now;
        m_pulseCount -= 1;
        m_currentMaxLevel = random(m_minLevel, m_maxLevel);
        m_currentMaxLevel = constrain(m_currentMaxLevel, 0, 255);
    }
    
    if (now > (m_t + m_pulseLengthMSec)) {
        // pause
        scale = 0;
    } else if (now > (m_t + pulseHalf)) {
        // fall
        float diff = now - m_t - pulseHalf;
        scale = (1.0f - diff / pulseHalf);
    } else {
        // rise
        float diff = now - m_t;
        scale = diff / pulseHalf;
    }

    uint8_t value = m_minLevel + (m_currentMaxLevel - m_minLevel) * scale;
    value = constrain(value, 0, 255);

    analogWrite(m_pin, m_isActive ? value : 0);

    if (m_pulseCount <= 0) {
        m_calcNewValues = true;
        m_sleepUtil = now + m_sequencePauseMSec;
    }
}
