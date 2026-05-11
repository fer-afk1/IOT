const int PIN_TACTIL = T0;
const int PIN_LED = 2;
const int UMBRAL = 800;
const int TIEMPO_DOBLE_TOQUE = 400; 

bool estadoLED = false;
bool primerToque = false;
unsigned long tiempoPrimerToque = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  Serial.println("Doble toque para cambiar el LED");
}

void loop() {
  int valor = touchRead(PIN_TACTIL);

  if (valor < UMBRAL) {
    if (!primerToque) {
      // Primer toque 
      primerToque = true;
      tiempoPrimerToque = millis();
      Serial.println("Primer toque...");
      delay(200); 

    } else {
      // Segundo toque 
      if (millis() - tiempoPrimerToque < TIEMPO_DOBLE_TOQUE) {
        estadoLED = !estadoLED;
        digitalWrite(PIN_LED, estadoLED);
        Serial.print("Doble toque! LED: ");
        Serial.println(estadoLED ? "ENCENDIDO" : "APAGADO");
      }
      primerToque = false;
      delay(200); 
    }
  }

  // Si pasó mucho tiempo
  if (primerToque && millis() - tiempoPrimerToque > TIEMPO_DOBLE_TOQUE) {
    primerToque = false;
    Serial.println("Tiempo agotado, intenta de nuevo");
  }

  delay(10);
}