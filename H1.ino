#include <WiFi.h>

const char* ssid     = "TU_SSID";
const char* password = "TU_PASSWORD";

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.print("Conectando");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println(" ya esta conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {}