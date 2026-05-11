const int PIN_FLOTANTE = 34;
const int PIN_REF = 35; 

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Pin flotante vs Pin con referencia ");
  Serial.println("Flotante | Referencia");
}

void loop() {
  int flotante = analogRead(PIN_FLOTANTE);
  int referencia = analogRead(PIN_REF);

  Serial.print(flotante);
  Serial.print(" | ");
  Serial.println(referencia);

  delay(500);
}