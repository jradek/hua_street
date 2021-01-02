#include "on_off.h"

#include <Arduino.h>


OnOff::OnOff(uint8_t pin)
    : m_pin(pin)
    , m_t(millis())
{}


void OnOff::update() {
    unsigned long now = millis();
    unsigned long diff = now - m_t;
    float value = 0;

    //Serial.printf("now %d, diff %d\n", now, diff);

    switch(m_mode) {
        case Mode::Off:
            if (diff > m_offTimeMSec) {
                m_t = now;
                m_mode = Mode::Rise;
                // Serial.printf("Switch to rise\n");
            }
            value = 0.0;
            break;
        case Mode::Rise:
            if (diff > m_riseTimeMSec) {
                value = 1.0;
                m_t = now;
                m_mode = Mode::On;
                // Serial.printf("Switch to on\n");
            } else {
                value = float(diff) / float(m_riseTimeMSec);
                //Serial.printf("Rise %f\n", value);
            }
            break;
        case Mode::On:
            if (diff > m_onTimeMSec) {
                m_t = now;
                m_mode = Mode::Fall;
                // Serial.printf("Switch to fall\n");
            }
            value = 1.0f;
            break;
        case Mode::Fall:
            if (diff > m_fallTimeMSec) {
                value = 0.0;
                m_t = now;
                m_mode = Mode::Off;
                // Serial.printf("Switch to off\n");
            } else {
                value = 1.0f - float(diff) / float(m_fallTimeMSec);
                // Serial.printf("Fall %f\n", value);
            }
            break;
    }

    performOutput(value);
}

void OnOff::performOutput(float value) {
    float range = m_maxLevel - m_minLevel;
    int16_t res = m_minLevel + range * value;
    res = constrain(res, m_minLevel, m_maxLevel);
    analogWrite(m_pin, m_isActive ? res : 0);
}


