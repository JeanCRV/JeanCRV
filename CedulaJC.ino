String cedulaGuion;
int cedulaP1;
int cedulaP2;
int vec[]={2,1,2,1,2,1,2,1,2};
int mul;
int sum;

void setup() {
  Serial.begin(9600);
  Serial.println("INGRESE UN NUMERO DE CEDULA CON EL GUION (-) ANTES DEL ULTIMO NUMERO");

}

void loop() {

  if(Serial.available()>0){

  cedulaGuion=Serial.readString();
  Serial.println("");
  
  if(cedulaGuion.length()==11){                                 //condiciones de ingreso
    if(cedulaGuion.substring(9,10)=="-"){
      Serial.println("SE HAN INGRESADO 11 DIGITOS INCLUYENDO GRUION (-)");
      
      int numProvincia = (cedulaGuion.substring(0,2)).toInt();  //tomo los primeros 2 numeros
      int digito3 = (cedulaGuion.substring(2,3)).toInt();       //tomo el tercer numero
      if(numProvincia < 24){                                    //compruebo que sea menor a 24
        if(digito3 < 6){

          cedulaP2 = (cedulaGuion.substring(10,11)).toInt();
          
          for (int i = 0; i < 9 ; i++) { 
            mul = vec[i] * (cedulaGuion.substring(i, i + 1)).toInt();   //multiplico los primeros 9 digitos por el vector
            if (mul > 9) {                                              //compruebo condicion
              mul = mul - 9;                                            //
            }
            sum = sum + mul;
          }

          if (sum % 10 == 0) {                                          //condiciones de cedula
            if (sum / 10 == cedulaP2){                                  //suma igual a ultimo digito de la cedula
              
              Serial.println("* CEDULA CORRECTA *");
              
            }
          } else {
            int comprobar = 10 - (sum % 10);
            if (comprobar == cedulaP2) {
              Serial.println("* CEDULA CORRECTA *");
              sum = 0;
            }
           }
          
        }else{
          Serial.println("El tercer digito es mayor a 6");              //mensajes de error
          }
        }else{
        Serial.println("El numero de provincia es incorrecto");
      }

      
          }else{
        Serial.println("No se ha ingresado el numero de cedula con un guion");
        }
      }else{
      Serial.println("Los digitos ingresados deben ser 11 incluido guion (-)");
    }
  }

}
