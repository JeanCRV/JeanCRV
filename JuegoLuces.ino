
int i=0;
String var;
int leds[5]={9,10,11,12,13};
int a;

void setup() {
Serial.begin(9600);
Serial.println("Ingrese la combinacion para encender los Leds");
for(i=0;i<5;i++){
  pinMode(leds[i],OUTPUT);
  }
}

void loop() {

  if(Serial.available()>0){
  var = Serial.readString();
  Serial.println("");
  a=1;
  
  }
  if(a==1){
  if(var == "ACBF"){
    
    
  for (int j=0;j<5;j++){
    digitalWrite(leds[j],HIGH);
    delay(150);
    digitalWrite(leds[j],LOW);
    delay(150);
  }
    
  }
  if(var == "ACGF"){
    
    
  for (int j=0;j<5;j+=2){
    digitalWrite(leds[j],HIGH);
    delay(150);
    digitalWrite(leds[j],LOW);
    delay(150);
  }

    
  }

  if(var=="ADBF"){

    digitalWrite(9,HIGH);
    digitalWrite(13,!digitalRead(9));
    delay(150);
    digitalWrite(9,LOW);
    digitalWrite(13,!digitalRead(9));
    delay(150);
    
  }

  if(var=="ADBH"){

    for(int j=0;j<5;j++){

      for(int i=0;i<32;i++){
      for(int j=0;j<5;j++){
        if (((i >> j) & 1) == 1){
          digitalWrite(leds[j],HIGH);
        }
        else digitalWrite(leds[j],LOW);
      }
      delay(150);
    }
    
  }
  
  


    
    
    }


  }
}
