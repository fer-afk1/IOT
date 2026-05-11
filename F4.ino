// F4 - Calibrar umbral de detección táctil
// LIS428 - Fundamentos de IoT | Universidad De La Salle Bajío

const int PIN_TACTIL = T0;
int umbral = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Calibrando... no toques el pin");
  delay(2000);

  // Toma 10 lecturas sin contacto para calcular el umbral
  long suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += touchRead(PIN_TACTIL);
    delay(100);
  }
  int promedio = suma / 10;
  umbral = promedio * 0.6; // 60% del valor libre = umbral de toque

  Serial.print("Promedio sin contacto: ");
  Serial.println(promedio);
  Serial.print("Umbral de deteccion: ");
  Serial.println(umbral);
  Serial.println("Ahora toca el pin!");
}

void loop() {
  int valor = touchRead(PIN_TACTIL);

  Serial.print("Valor: ");
  Serial.print(valor);
  Serial.print(" | Estado: ");

  if (valor < umbral) {
    Serial.println("TOCADO");
  } else {
    Serial.println("sin contacto");
  }

  delay(200);
}