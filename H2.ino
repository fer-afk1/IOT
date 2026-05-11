#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid     = "TU_SSID";
const char* password = "TU_PASSWORD";
const char* broker   = "broker.hivemq.com";
const char* topico   = "lis428/temperatura";

DHT sensor(4, DHT11);
WiFiClient wifi;
PubSubClient mqtt(wifi);

void setup() {
  Serial.begin(115200);
  sensor.begin();

  WiFi.begin(ssid, password);
  Serial.print("Conectando WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" listo!");

  mqtt.setServer(broker, 1883);

  while (!mqtt.connected()) {
    Serial.print("Conectando MQTT...");
    if (mqtt.connect("ESP32_G")) {
      Serial.println(" ok");
    } else {
      delay(2000);
    }
  }
}

void loop() {
  if (!mqtt.connected()) {
    mqtt.connect("ESP32_G");
  }
  mqtt.loop();

  float temp = sensor.readTemperature();

  if (!isnan(temp)) {
    char msg[10];
    dtostrf(temp, 4, 2, msg);
    mqtt.publish(topico, msg);
    Serial.print("Publicado: ");
    Serial.println(msg);
  }

  delay(3000);
}