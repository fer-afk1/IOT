
const int PIN_ADC = 34;
int contador = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  if  (contador <= 20) {
    int lectura = analogRead(PIN_ADC);
    Serial.println(lectura);
    contador++;
    delay(1000); 
  }
}