
const bool CON_INSTRUCCIONES = true;

unsigned long tiempoInicio;
unsigned long tiempoFin;
unsigned long duracion;
int ciclo = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== A5: Medición de tiempo de ejecución del loop ===");
  if (CON_INSTRUCCIONES) {
    Serial.println("Modo: CON instrucciones");
  } else {
    Serial.println("Modo: Loop VACÍO (sin instrucciones útiles)");
  }
  Serial.println("----------------------------------------------------");
}

void loop() {
  tiempoInicio = micros(); // Marca el inicio del ciclo

  if (CON_INSTRUCCIONES) {
    int suma = 0;
    for (int i = 0; i < 1000; i++) {
      suma += i;
    }
    float raiz = sqrt(12345.678);
    int x = analogRead(34); 
    (void)suma; (void)raiz; (void)x;
  }


  tiempoFin = micros(); 
  duracion = tiempoFin - tiempoInicio;

  ciclo++;
  Serial.print("Ciclo ");
  Serial.print(ciclo);
  Serial.print(" | Duración: ");
  Serial.print(duracion);
  Serial.println(" µs");

  delay(500);
}
