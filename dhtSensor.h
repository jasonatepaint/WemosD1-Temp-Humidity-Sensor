#ifndef dhtSensor_h
#define dhtSensor_h

#include "Arduino.h"
#include "mqttClient.h"
#include <DHT.h>
#include <Adafruit_Sensor.h>

class DhtSensor
{
  public:
    DhtSensor(const char* topic);
    void setup();
    void loop(MQTTClient* client);

  private:
    const char *_topic;
};

#endif
