#ifndef mqttClient_h
#define mqttClient_h

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>

class MQTTClient
{
  public:
    MQTTClient(const char *ssid, const char *password, const char *mqttServer, const int port, const char *mqttUser, const char *mqttPassword);
    void setup();
    void loop();
    void publish(const char* topic, const char* payload, boolean retained);
  private:
    WiFiClient _wifiClient;
    PubSubClient* _subClient;
    const char *_ssid;
    const char *_password;
    const char *_mqttServer;
    const char *_mqttUser;
    const char *_mqttPassword;
    int _port;
    void _reconnect();
};

#endif
