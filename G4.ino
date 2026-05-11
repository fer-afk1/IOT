#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>

BH1750 luz;
DHT sensor(4, DHT11);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  luz.begin();
  sensor.begin();
  delay(2000);
  Serial.println("Luz (lux) | Temp (C) | Humedad (%)");
}

void loop() {
  float lux  = luz.readLightLevel();
  float temp = sensor.readTemperature();
  float hum  = sensor.readHumidity();

  Serial.print(lux);
  Serial.print(" lux  |  ");
  Serial.print(temp);
  Serial.print(" C  |  ");
  Serial.print(hum);
  Serial.println(" %");

  delay(1500);
}