#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Iniciando escaneo de redes WiFi...");
}

void loop() {
  Serial.println("\nBuscando redes cercanas...");
  int redes = WiFi.scanNetworks();

  if (redes == 0) {
    Serial.println("No encontre ninguna red");
  } else {
    Serial.print("Encontre ");
    Serial.print(redes);
    Serial.println(" redes:");
    Serial.println("-------------------------------");

    for (int i = 0; i < redes; i++) {
      Serial.print(i + 1);
      Serial.print(". ");
      Serial.print(WiFi.SSID(i));
      Serial.print("  |  Señal: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" dBm  |  Canal: ");
      Serial.println(WiFi.channel(i));
    }

    Serial.println("-------------------------------");
  }

  Serial.println("Esperando 5 segundos...\n");
  delay(5000);
}