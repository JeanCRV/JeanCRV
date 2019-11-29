int limite=0;
int a=0;
int valor;

void setup() {
 
  
    pinMode(8,OUTPUT);
    
  Serial.begin(9600);
  Serial.println("Ingrese el Limite del Lector Analogico");
}

void loop() {

 
 if(Serial.available()>0){
  limite = Serial.parseInt();
  a=1;
 }
 if(a==1){
if (limite>0 && limite<1023){

valor = analogRead(0);

    if(limite < valor){      
Serial.println(" ");
Serial.print("El valor analogico es: ");
Serial.print(valor);
Serial.print(" Led Encendido");
  digitalWrite(8,HIGH);
  
delay(300);
      
    }else{
Serial.println(" ");
Serial.print("El valor analogico es: ");
Serial.print(valor);
Serial.print(" Led Apagado");
  digitalWrite(8,LOW);

delay(300);           

    }

}else{
    Serial.println("El valor ingresado es superior a 1023");
    delay(1000);
  }}

 
 
}
