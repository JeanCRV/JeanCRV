#include <LiquidCrystal.h> 
LiquidCrystal lcd(13,12,11,10,9,8);
 
String palabra;
 
void setup() {
  
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Ingrese el Texto");
}
 
void loop() {

  if(Serial.available()>0){
  palabra = Serial.readStringUntil('\n');
  Serial.println("");
  }
  if(palabra != " "){
  int tam_palabra = palabra.length();
 
  // Mostramos entrada texto por la izquierda
  lcd.clear();
  delay(300);
  for(int i=tam_palabra; i>0 ; i--){
    
    String texto = palabra.substring(i-1);

    lcd.setCursor(0, 0);
    lcd.print(texto);
    delay(300);
  }
 
  // Desplazamos el texto hacia la derecha
  for(int i=1; i<=16;i++){
    
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.print(palabra);
    delay(300);
    
  }
 
  // Desplazamos el texto hacia la izquierda en la segunda fila
  for(int i=16;i>=1;i--){

    lcd.clear();
    lcd.setCursor(i, 1);
    lcd.print(palabra);
    delay(300);
    
  }
 
  // Mostramos salida del texto por la izquierda
  for(int i=1; i<=tam_palabra ; i++){
    
    String texto = palabra.substring(i-1);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(texto);
    delay(300);
    
    }
  }
}
