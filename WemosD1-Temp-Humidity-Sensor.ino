#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

#include "config.h"
#include "mqttClient.h"
#include "dhtSensor.h"
#include "codeOTA.h"

MQTTClient *mqttClient;
DhtSensor *dhtSensor;
CodeOTA *codeOTA;

const int sleepTimeS = 10;

void setup(void) {
  mqttClient = new MQTTClient(ssid, password, mqttServer, mqttPort, mqttUser, mqttPassword);
  mqttClient->setup();

  dhtSensor = new DhtSensor(topicTemperature);
  dhtSensor->setup();

  //codeOTA = new CodeOTA(otaHostName, otaPassword);
  //codeOTA->setup();

  Serial.begin(9600);

  //codeOTA->loop();
  mqttClient->loop();
  dhtSensor->loop(mqttClient);

  //Low Power Save Mode --
  sleep();
}

void loop(void) {
    //Not required, since Sleep causes a reboot on power up.
}

void sleep() {
    delay(100);
    Serial.println("powering down");
    ESP.deepSleep(sleepTimeS * 1000000);
}
