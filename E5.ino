const int PIN_LED = 2;
int frecuencia = 5000;
int dutyCycle = 128;

void setup() {
  Serial.begin(115200);
  delay(3000);

  ledcAttach(PIN_LED, frecuencia, 8);
  ledcWrite(PIN_LED, dutyCycle);

  Serial.println("Controla el LED desde aqui");
  Serial.println("Escribe d con un numero del 0 al 255 para cambiar el brillo");
  Serial.println("Escribe f con un numero para cambiar la frecuencia");
}

void loop() {
  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando.startsWith("d")) {
      dutyCycle = constrain(comando.substring(1).toInt(), 0, 255);
      ledcWrite(PIN_LED, dutyCycle);
      Serial.print("Brillo cambiado a ");
      Serial.print(dutyCycle);
      Serial.println(" (0 = apagado, 255 = maximo)");

    } else if (comando.startsWith("f")) {
      frecuencia = comando.substring(1).toInt();
      ledcAttach(PIN_LED, frecuencia, 8);
      ledcWrite(PIN_LED, dutyCycle);
      Serial.print("Frecuencia cambiada a ");
      Serial.print(frecuencia);
      Serial.println(" Hz");

    } else {
      Serial.println("No entendi ese comando. Prueba con d128 o f1000");
    }
  }
}