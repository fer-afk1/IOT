const int LED1 = 2; 
const int LED2 = 4; 
const int LED3 = 5; 

unsigned long tiempoAnterior1 = 0;
unsigned long tiempoAnterior2 = 0;
unsigned long tiempoAnterior3 = 0;

bool estado1 = false;
bool estado2 = false;
bool estado3 = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(115200);
  Serial.println("=== B5: Secuencia de 3 LEDs con millis() ===");
  Serial.println("LED1: 500ms | LED2: 1000ms | LED3: 1500ms");
}

void loop() {
  unsigned long ahora = millis();

  // LED 1 - cada 500ms
  if (ahora - tiempoAnterior1 >= 500) {
    tiempoAnterior1 = ahora;
    estado1 = !estado1;
    digitalWrite(LED1, estado1);
    Serial.print("LED1: ");
    Serial.println(estado1 ? "ON" : "OFF");
  }

  // LED 2 - cada 1000ms
  if (ahora - tiempoAnterior2 >= 1000) {
    tiempoAnterior2 = ahora;
    estado2 = !estado2;
    digitalWrite(LED2, estado2);
    Serial.print("LED2: ");
    Serial.println(estado2 ? "ON" : "OFF");
  }

  // LED 3 - cada 1500ms
  if (ahora - tiempoAnterior3 >= 1500) {
    tiempoAnterior3 = ahora;
    estado3 = !estado3;
    digitalWrite(LED3, estado3);
    Serial.print("LED3: ");
    Serial.println(estado3 ? "ON" : "OFF");
  }
}