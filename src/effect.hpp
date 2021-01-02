#ifndef EFFECT_HPP
#define EFFECT_HPP

class Effect {
public:
    virtual void setup() {}

    virtual inline void setActive(boolean active) {
        m_isActive = active;
    }

    virtual void update() = 0;

protected:
    boolean m_isActive = true;
};

#endif // EFFECT_HPP