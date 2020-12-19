#ifndef EFFECT_HPP
#define EFFECT_HPP

class Effect {
public:
    virtual void setup() {}
    virtual void update() = 0;
};

#endif // EFFECT_HPP