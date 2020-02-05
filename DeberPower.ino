#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int cont = 0;
int valor;
int a = 0;

void setup() {
  wdt_disable();
  power_adc_enable();
  power_usart0_enable();
  Serial.begin(9600);
  lcd.begin(16, 2);
  set_sleep_mode(SLEEP_MODE_ADC);
  MsTimer2::set(1000, conteodos); //1 segundo
  MsTimer2::start();
  lcd.setCursor(5, 0);
  lcd.print("SISTEMA");
  lcd.setCursor(4, 1);
  lcd.print("ACTIVADO");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print("LECTURA CAD ");


}

void loop() {

  lectura();

}


void conteodos() {
  cont++;

  lcd.setCursor(0, 1);
  lcd.print("  ");
  lcd.setCursor(0, 1);
  lcd.print(cont);

  if (cont == 5) {
    lcd.setCursor(5, 1);
    lcd.print("CAD DES");
    power_adc_disable();
  }

  if (cont == 8) {
    lcd.setCursor(5, 1);
    lcd.print("        ");
    lcd.setCursor(5, 1);
    lcd.print("SERIAL DES");
    power_usart0_disable();
  }

  if (cont == 12) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("SISTEMA");
    lcd.setCursor(3, 1);
    lcd.print("DESACTIVADO");
  }
  if(cont==13){
    lcd.clear();
    dormir();
  }

}

void dormir() {

  wdt_reset();
  wdt_enable(WDTO_4S);
  sleep_enable();
  power_all_disable();
  sleep_mode();
  sleep_disable();
  power_all_enable();

}

void lectura() {
  valor = analogRead(0);
  Serial.println(valor);
  lcd.setCursor(12, 0);
  lcd.print("    ");
  lcd.setCursor(12, 0);
  lcd.print(valor);
  delay(100);
}
