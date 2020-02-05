#include <avr/wdt.h>

String var;

void setup() {
  wdt_disable();
  Serial.begin(9600);
  Serial.println("SISTEMA INICIADO");
  Serial.println("Ingrese el Tiempo de RESET");

}

void loop() {
  if (Serial.available() > 0) {
    var = Serial.readString();


    if (var == "A") {
      Serial.println(" ");
      Serial.println("El Sistema se Reiniciara en 1 segundo");
      wdt_reset();
      wdt_enable(WDTO_1S);
    } else if (var == "B") {
      Serial.println(" ");
      Serial.println("El Sistema se Reiniciara en 2 segundos");
      wdt_reset();
      wdt_enable(WDTO_2S);
    } else if (var == "C") {
      Serial.println(" ");
      Serial.println("El Sistema se Reiniciara en 4 segundos");
      wdt_reset();
      wdt_enable(WDTO_4S);
    } else if (var == "D") {
      Serial.println(" ");
      Serial.println("El Sistema se Reiniciara en 8 segundos");
      wdt_reset();
      wdt_enable(WDTO_8S);
    } else {
      Serial.println(" ");
      Serial.println("Caracter Ingresado Invalido");
    }
  }
}
