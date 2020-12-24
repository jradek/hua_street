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


void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  waterMill.setOnTime(1000).setOffTime(500).setRiseTime(1000).setFallTime(10);

  ancientHall.setLevel(10, 255).setPulses(2, 10);
  butcher.setLevel(10, 255).setPulses(2, 5);

  vinegar.setLevel(30, 200);
  rice.setLevel(30, 200);

  // restaurant1.setMaxLevel(2000).setIncrement(100, 100);

  Serial.begin(9600);
}

void loop() {
  waterMill.update();
  ancientHall.update();
  butcher.update();

  vinegar.update();
  rice.update();
  restaurant1.update();
  restaurant2.update();
}