#include <TimerOne.h>
#include <LiquidCrystal.h>

#include <Keypad.h>
const byte fil = 4;
const byte col = 4;
char keys[fil][col] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinFil[fil] = {11, 10, 9, 8};
byte pinCol[col] = {7, 6, 5, 4};
Keypad teclado = Keypad(makeKeymap(keys), pinFil, pinCol, fil, col);  // crea objeto

LiquidCrystal lcd(13, 12, A0, A1, A2, A3);

char valor;
String dato;
int i = 0;
int valor_int;
int numero;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("INGRESE TIEMPO");

  
}

void loop() {
  valor = teclado.getKey();
  if (valor) {
    dato = dato + valor;
  }
  lcd.setCursor(0, 1);
  lcd.print(dato);

  valor_int = dato.toInt();

  if(valor == 'A'){
    Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  }

}



void conteo() {

 if (valor_int > 0) {
 numero = valor_int-1;
    valor_int=numero;
    Serial.println(valor_int);
    //    lcd.clear();
    //    lcd.setCursor(7, 1);
    //lcd.clear();
    //lcd.print(valor_int);
  }
}
