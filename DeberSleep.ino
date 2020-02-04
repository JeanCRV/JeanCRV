#include <avr/power.h>
#include <TimerOne.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <MsTimer2.h>

int a = 0;
int cont = 0;

void setup() {
  set_sleep_mode(SLEEP_MODE_ADC);
  sleep_disable();
  power_all_enable();
  Serial.begin(9600);

  MsTimer2::set(1000, conteodos); //1 segundo
  MsTimer2::start();
  Serial.println("Sistema Activado");

}

void loop() {

  if (a == 1) {
    if (cont == 2) {
      a = 0;
      Serial.println("Ahorro de Energia");
      delay(10);
    }
  }
}

void conteodos() {
  cont++;
  if (cont < 3) {
    Serial.println(cont);
    a = 1;
  }

  if (cont == 3) {
    dormir();
  }
}

void dormir() {

  wdt_reset();
  wdt_enable(WDTO_8S);
  sleep_enable();
  power_all_disable();
  sleep_mode();
  sleep_disable();
  power_all_enable();

}
