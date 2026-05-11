#include <DHT.h>

DHT sensor(4, DHT11);

void setup() {
  Serial.begin(115200);
  sensor.begin();
  delay(2000);

  float lecturas[10];
  float suma = 0;

  for (int i = 0; i < 10; i++) {
    lecturas[i] = sensor.readTemperature();
    Serial.print("Lectura ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(lecturas[i]);
    Serial.println(" C");
    suma += lecturas[i];
    delay(1500);
  }

  Serial.print("Promedio: ");
  Serial.print(suma / 10);
  Serial.println(" C");
}

void loop() {}