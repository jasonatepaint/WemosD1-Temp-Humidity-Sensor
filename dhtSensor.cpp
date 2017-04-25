#include "dhtSensor.h"

#define DHTPIN 2

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

DhtSensor::DhtSensor(const char* topic) {
  _topic = topic;
}

void DhtSensor::setup() {
  dht.begin();
}

void DhtSensor::loop(MQTTClient* client) {
    
  float h = dht.readHumidity();
  float temperature = dht.readTemperature(true); //true for F
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  //Build Json msg
  char tc[10];
  char hc[4];
  dtostrf(temperature, 6, 1, tc);
  dtostrf(h, 3, 1, hc);
  String temperatureString = String(tc);
  String humidityString = String(hc);
  temperatureString.trim();
  humidityString.trim();
  
  String msg = "{\"temperature\": \"" + temperatureString + "\", \"humidity\": \"" + humidityString + "\"}";
  Serial.println(msg);
  
  int len = msg.length();
  char msg_buffer[len];
  msg.toCharArray(msg_buffer, len + 1);

  if (client) {
    client->publish(_topic, msg_buffer, true);
  }
}


