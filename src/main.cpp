#include <Arduino.h>

#include "fire_level.h"
#include "on_off.h"
#include "pulse.hpp"

FireLevel fire(D5);
OnOff onOff(D5, 2000, 100, 500, 200, 50, 220);
Pulse pulse1(D5);
Pulse pulse2(D6);

void setup() {
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

  pulse1.setLevel(0, 255);
  pulse1.setPulses(1, 5);
  pulse1.setPulse(500, 10);
  pulse1.setLevel(0, 100);

  pulse2.setLevel(40, 255);
  pulse2.setPulses(2, 10);

  Serial.begin(9600);
}

void loop() {
  pulse1.update();
  pulse2.update();
}