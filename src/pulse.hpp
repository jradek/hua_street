#ifndef PULSE_HPP
#define PULSE_HPP

#include <Arduino.h>
#include "effect.hpp"

/**
 * See: https://elektro.turanis.de/html/prj175/index.html
 */
class Pulse : public Effect {
public:
    explicit Pulse(uint8_t pin);

    inline void setup() {
        pinMode(m_pin, OUTPUT);
    }

    inline Pulse& setPulses(uint8_t minPulses, uint8_t maxPulses) {
        m_minPulses = minPulses;
        m_maxPulses = maxPulses;
        return *this;
    }

    inline Pulse& setLevel(uint8_t minLevel, uint8_t maxLevel) {
        m_minLevel = minLevel;
        m_maxLevel = m_maxLevel;
        return *this;
    }

    inline Pulse& setPulse(unsigned pulseLengthMSec, unsigned pulsePauseMSec) {
        m_pulseLengthMSec = pulseLengthMSec;
        m_pulsePauseMSec = pulsePauseMSec;
        return *this;
    }

    inline Pulse& setSequencePause(unsigned msec) {
        m_sequencePauseMSec = msec;
        return *this;
    } 

    void update();

private:
    uint8_t m_pin;
    unsigned long m_t;
    unsigned long m_sleepUtil = 0;

    // minimum pulses in a sequence
    uint8_t m_minPulses = 2;
    // maximum pulses in a sequence
    uint8_t m_maxPulses = 5;

    // minimum level of a pulse
    uint8_t m_minLevel = 0;
    // maximum level of a pulse
    uint8_t m_maxLevel = 255;
    uint8_t m_currentMaxLevel = 255;

    // duration of rise/fall off a pulse [msec]
    unsigned long m_pulseLengthMSec = 1000;
    // pause between pulses [msec]
    unsigned long m_pulsePauseMSec = 500;

    uint8_t m_pulseCount = 2;

    // pause between sequences
    unsigned long m_sequencePauseMSec = 2000;
    bool m_calcNewValues = true;
};

#endif 