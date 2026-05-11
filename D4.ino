const int PIN_ADC = 34;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== D4: constrain() + map() ===");
  Serial.println("ADC raw | map() | constrain()+map()");
}

void loop() {
  int raw = analogRead(PIN_ADC);

  int mapeado = map(raw, 0, 4095, 0, 255);

  int acotado = constrain(mapeado, 50, 200);

  Serial.print(raw);
  Serial.print(" | ");
  Serial.print(mapeado);
  Serial.print(" | ");
  Serial.println(acotado);

  delay(500);
}