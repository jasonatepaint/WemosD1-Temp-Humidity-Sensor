# WemosD1 ESP8266 based DHT22 Temperature sensor

- https://www.wemos.cc/product/d1-mini.html
- https://www.wemos.cc/product/dht-pro-shield.html

Code for building a Wemos D1 ESP8266 based temperature & Humidity sensor. 

Features:
---------
- Publishes changes to MQTT which be used by Home Assistant and other home automation hubs
- Supports over the air updates
- Everything is local (on your wifi - no cloud portion)

How to Use:
-----------
- Copy config.sample.h to config.h and change the values to your configuration
- Use arduino IDE to publish to flash. 
