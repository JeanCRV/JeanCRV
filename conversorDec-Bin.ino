int valor;
int division;
int i;
int vec[8]={};
int leds[8]={13,12,11,10,9,8,7,6};
void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese un Numero Para Convertir a Binario");
  
  for(int j=0;j<8;j++){              //ingreso pines de salida
pinMode(leds[j],OUTPUT);    
  }
}

void loop() {

  if(Serial.available()>0){

  valor = Serial.parseInt();
  Serial.println("");
  if(valor<256){                      //condición para numeros representados por 8 bits
  Serial.print("El numero ingresado es "+String (valor)+", su valor en binario es ");
  
                                      //el programa realiza el numero de operaciones necesarias hasta que
      for(i=7;i>=0;i--){              // el valor ingresado ya no sea divisible para 2.
        vec[i]= valor%2;              // Ingreso del "resto", de la division para 2, en el vector
        valor = valor/2;              
      }
                  

 for(int j=0;j<8;j++){
    Serial.print(vec[j]);             // Impresio del numero binario por serial
 }
 Serial.println("");
 
 for(int j=8;j>=0;j--){
  if(vec[j]==1){                      // Encendido de los leds en la posicion del vector que contiene  el numero binario.
    digitalWrite(leds[j],HIGH);
  }else{
    digitalWrite(leds[j],LOW);
  }
 }
    }else{                            // Mensaje de error
      Serial.println("El numero ingresado supera al valor representado por 8 bits");
    }
  }
}
