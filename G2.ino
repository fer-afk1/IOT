#include <DHT.h>

DHT sensor(4, DHT11);

void setup() {
  Serial.begin(115200);
  sensor.begin();
}

void loop() {
  float temp = sensor.readTemperature();
  float hum  = sensor.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("No se pudo leer el sensor.");
    delay(2000);
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" C   Humedad: ");
  Serial.print(hum);
  Serial.println(" %");

  delay(2000);
}