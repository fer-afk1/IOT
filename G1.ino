#include <Wire.h>

void setup() {
  Serial.begin(115200);
  delay(2000); // le das tiempo al Serial de inicializarse

  Wire.begin(21, 22); // SDA=21, SCL=22 (pines por defecto del ESP32)

  Serial.println("Escaneando bus I2C...");

  int encontrados = 0;

  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo encontrado en 0x");
      Serial.println(addr, HEX);
      encontrados++;
    }
  }

  if (encontrados == 0) {
    Serial.println("No se encontraron dispositivos.");
  } else {
    Serial.print(encontrados);
    Serial.println(" dispositivo(s) encontrado(s).");
  }

  Serial.println("Escaneo completo.");
}

void loop() {}
