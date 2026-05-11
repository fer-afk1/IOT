#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();
  delay(1000);

  Serial.println("Buscando dispositivos en el bus I2C...");

  for (byte dir = 1; dir < 127; dir++) {
    Wire.beginTransmission(dir);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo en: 0x");
      Serial.println(dir, HEX);
    }
  }

  Serial.println("Listo");
}

void loop() {}