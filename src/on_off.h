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
    OnOff(uint8_t pin, 
        unsigned onTimeMSec, 
        unsigned offTimeMSec, 
        unsigned riseTimeMSec,
        unsigned fallTimeMSec,
        uint8_t minLevel = 0,
        uint8_t maxLevel = 255);

    void update();

private:
    void performOutput(float value);

    uint8_t m_pin;
    unsigned long m_t;
    unsigned m_onTimeMSec;
    unsigned m_offTimeMSec;
    unsigned m_riseTimeMSec;
    unsigned m_fallTimeMSec;
    uint8_t m_minLevel;
    uint8_t m_maxLevel;
    Mode m_mode;
};

#endif