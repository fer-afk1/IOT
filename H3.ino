#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid     = "TU_SSID";
const char* password = "TU_PASSWORD";
const char* broker   = "broker.hivemq.com";
const char* topico   = "lis428/led";

const int LED = 5;

WiFiClient wifi;
PubSubClient mqtt(wifi);

void alLlegarMensaje(char* topic, byte* payload, unsigned int len) {
  String msg = "";
  for (int i = 0; i < len; i++) msg += (char)payload[i];
  msg.trim();

  Serial.print("Mensaje: ");
  Serial.println(msg);

  if (msg == "ENCENDER") {
    digitalWrite(LED, HIGH);
    Serial.println("LED encendido");
  } else if (msg == "APAGAR") {
    digitalWrite(LED, LOW);
    Serial.println("LED apagado");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Conectando WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println(" listo");

  mqtt.setServer(broker, 1883);
  mqtt.setCallback(alLlegarMensaje);

  while (!mqtt.connected()) {
    if (mqtt.connect("ESP32_H3")) {
      mqtt.subscribe(topico);
      Serial.println("Suscrito al topico");
    } else {
      delay(2000);
    }
  }
}

void loop() {
  if (!mqtt.connected()) {
    mqtt.connect("ESP32_H3");
    mqtt.subscribe(topico);
  }
  mqtt.loop();
}