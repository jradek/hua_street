#ifndef ON_OFF_HPP
#define ON_OFF_HPP

#include <Arduino.h>

#include "effect.hpp"

class OnOff : public Effect 
{
    enum Mode {
        On = 0,
        Off = 1,
        Rise = 2,
        Fall = 3
    };

public:
    explicit OnOff(uint8_t pin);

    inline void setup() {
        pinMode(m_pin, OUTPUT);
    }

    inline OnOff& setOnTime(unsigned msec) {
        m_onTimeMSec = msec;
        return *this;
    }

    inline OnOff& setOffTime(unsigned msec) {
        m_offTimeMSec = msec;
        return *this;
    }

    inline OnOff& setRiseTime(unsigned msec) {
        m_riseTimeMSec = msec;
        return *this;
    }

    inline OnOff& setFallTime(unsigned msec) {
        m_fallTimeMSec = msec;
        return *this;
    }

    inline OnOff& setLevel(uint8_t minLevel = 0, uint8_t maxLevel = 255) {
        m_minLevel = minLevel;
        m_maxLevel = maxLevel;
        return *this;
    }

    void update();

private:
    void performOutput(float value);

    uint8_t m_pin;
    unsigned long m_t;
    unsigned m_onTimeMSec = 1000;
    unsigned m_offTimeMSec = 1000;
    unsigned m_riseTimeMSec = 500;
    unsigned m_fallTimeMSec = 500;
    uint8_t m_minLevel = 0;
    uint8_t m_maxLevel = 255;
    Mode m_mode;
};

#endif