#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "fire_level.h"
#include "on_off.h"
#include "pulse.hpp"
#include "const.hpp"

#include "cred.hpp"

OnOff waterMill(D1);
Pulse ancientHall(D2);
Pulse butcher(D3);
Pulse vinegar(D4);
Pulse rice(D5);
FireLevel restaurant1(D6);
FireLevel restaurant2(D7);

uint8_t const c_numEffects = 7;

Effect *effects[c_numEffects] = {
    &waterMill,
    &ancientHall,
    &butcher,
    &vinegar,
    &rice,
    &restaurant1,
    &restaurant2};


ESP8266WebServer server(80);
boolean isActive = true;

// https://www.survivingwithandroid.com/esp8266-web-server/
void handle_home_page() {
  char body[1024];
  sprintf(body,  "<html><head>"
  "<title>Hua Street</title>"
  "<meta name='viewport' content='width=device-width, initial-scale=1.0'></head>"
  "<body><h1>Hi Micha, street is %s</h1></body></html>", isActive ? "on" : "off");
  server.send(200, "text/html", body);
}

void handle_street_on() {
  Serial.println("street on");
  isActive = true;
}

void handle_street_off() {
  Serial.println("street off");
  isActive = false;
}


void setup()
{
  // setup
  for (uint8_t i = 0; i < c_numEffects; ++i)
  {
    effects[i]->setup();
  }

  // configure
  waterMill.setOnTime(1000).setOffTime(500).setLevel(30, 200);

  ancientHall.setLevel(10, 255).setPulses(2, 10);
  butcher.setLevel(10, 255).setPulses(2, 5);

  vinegar.setLevel(30, 200);
  rice.setLevel(30, 200);

  // restaurant1.setMaxLevel(2000).setIncrement(100, 100);

  // wifi
  Serial.begin(9600);

  server.on("/", handle_home_page);
  server.on("/street/on", handle_street_on);
  server.on("/street/off", handle_street_off);
  server.begin();
}


void loop()
{
  for (uint8_t i = 0; i < c_numEffects; ++i)
  {
    effects[i]->setActive(isActive);
    effects[i]->update();
  }

  server.handleClient();
}