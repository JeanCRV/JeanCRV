#define btn 7
int i=0;
int j=0;
int on=0;

int leds[6]={8,9,10,11,12,13};

void setup() {
  for(;i<6;i++){
    pinMode(leds[i],OUTPUT);
    
  }
    pinMode(btn,INPUT);
}

void loop() {
int i=0, j=0;
  
if(digitalRead(btn)==HIGH){
    delay(300);
    on=1-on;
  }
    if(on==1){

    for(i=0;i<64;i++){
      for(j=0;j<6;j++){
        if (((i >> j) & 1) == 1){
          digitalWrite(leds[j],HIGH);
        }
        else digitalWrite(leds[j],LOW);
      }
      delay(300);
    }

  }    
  
}
