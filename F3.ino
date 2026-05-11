const int PIN_TACTIL = T0; //GPIO4

void setup() {
  Serial.begin(115200);
  delay(2000);
}

void loop() {
  int valor = touchRead(PIN_TACTIL);
  Serial.print("Valor tactil: ");
  Serial.println(valor);
  delay(200);
}