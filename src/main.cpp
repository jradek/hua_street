#include <Arduino.h>

#include "fire_level.h"
#include "on_off.h"
#include "pulse.hpp"
#include "const.hpp"


OnOff waterMill(D1);
Pulse ancientHall(D2);
Pulse butcher(D3);
Pulse vinegar(D4);
Pulse rice(D5);
FireLevel restaurant1(D6);
FireLevel restaurant2(D7);

uint8_t const c_numEffects = 7;

Effect* effects[c_numEffects] = {
  &waterMill,
  &ancientHall,
  &butcher,
  &vinegar,
  &rice,
  &restaurant1,
  &restaurant2
};


void setup() {
  // setup
  for (uint8_t i = 0; i < c_numEffects; ++i) {
    effects[i]->setup();
  }

  // configure
  waterMill.setOnTime(1000).setOffTime(500).setLevel(30, 200);

  ancientHall.setLevel(10, 255).setPulses(2, 10);
  butcher.setLevel(10, 255).setPulses(2, 5);

  vinegar.setLevel(30, 200);
  rice.setLevel(30, 200);

  // restaurant1.setMaxLevel(2000).setIncrement(100, 100);

  Serial.begin(9600);
}

void loop() {
  for (uint8_t i = 0; i < c_numEffects; ++i) {
    effects[i]->update();
  }
}