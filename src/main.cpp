#include <Arduino.h>

#include "fire_level.h"
#include "on_off.h"
#include "pulse.hpp"
#include "const.hpp"


OnOff waterMill(D1, 3000, 2000, 1000, 1000, 10, 255);
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

  ancientHall.setLevel(10, 255);
  ancientHall.setPulses(2, 10);
  butcher.setLevel(10, 255);
  butcher.setPulses(2,5);
  vinegar.setLevel(30, 200);
  rice.setLevel(30, 200);

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