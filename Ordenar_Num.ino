/*
 * Realizar un ejercicio en el cual tenga las etapas de: (i)Ingreso de datos y (ii) ordenamiento 
 * (i)Al ingresar la palabra solo pueden ser números por comunicación serial. 
 * (ii) Una vez ingresados lo números, ordenarlos de menor a mayor e imprimirlo por comunicación serial.
 * 
 */
int vec[]={};
int cont=0;
String nums;


void setup() {
  
  attachInterrupt(0,power,LOW);
  Serial.begin(9600);
  //attachInterrupt(1,ingreso,LOW);
}

void loop() {

if(cont==1){
  if(Serial.available()>0){
  nums=Serial.readString();
  Serial.println();
  Serial.println("El Numero Ingresado es: "+nums);
  Serial.print("El Numero Ordenado es:  ");
  int tam;
  tam = nums.length();
for(int i=0;i<tam;i++){                     //Guardar la cadena en el vector
      vec[i]=(nums.substring(i,i+1)).toInt();
    }

    for(int i=0;i<tam;i++){                   //Ordena el vector
      for(int j=0;j<tam;j++){
        if(vec[j]>vec[j+1]){
          int aux = vec[j];
          vec[j]=vec[j+1];
          vec[j+1]=aux;
        }
      }
    }
    for(int i=0;i<tam;i++){
    Serial.print(vec[i]);
  }
  Serial.println();
  
  }
 }
}

void power(){
  switch (cont){
    case 0:
    Serial.println("Sistema Encendido");
    Serial.println("Ingrese los Numeros a Ordenar");
    cont++;
    break;
    case 1:
    Serial.println("Ordenado");
    cont++;
    break;
    case 2:
    Serial.println("Sistema Apagado");
    cont=0;
    nums="";
    break;
  }
  
}
