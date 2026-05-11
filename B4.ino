const int PIN_LED = 2;
const long INTERVALO = 1000; 

unsigned long tiempoAnterior = 0;
bool estadoLED = false;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("=== LED con millis() ===");
}

void loop() {
  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoAnterior >= INTERVALO) {
    tiempoAnterior = tiempoActual;
    estadoLED = !estadoLED; 
    digitalWrite(PIN_LED, estadoLED);

    Serial.print("LED: ");
    Serial.println(estadoLED ? "ENCENDIDO" : "APAGADO");
  }

}