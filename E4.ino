const int PIN_LED = 2;

void setup() {
  ledcAttach(PIN_LED, 5000, 8); // pin, frecuencia y resolucion
  Serial.begin(115200);
}

void loop() {
  for (int brillo = 0; brillo <= 255; brillo++) {
    ledcWrite(PIN_LED, brillo);
    Serial.print("Brillo: ");
    Serial.println(brillo);
    delay(10);
  }

  for (int brillo = 255; brillo >= 0; brillo--) {
    ledcWrite(PIN_LED, brillo);
    Serial.print("Brillo: ");
    Serial.println(brillo);
    delay(10);
  }
}