#include <Wire.h>
#include <BH1750.h>

BH1750 luz;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  luz.begin();
  Serial.println("Sensor de luz listo");
}

void loop() {
  float lux = luz.readLightLevel();
  Serial.print("Luz: ");
  Serial.print(lux);
  Serial.println(" lux");
  delay(1000);
}
