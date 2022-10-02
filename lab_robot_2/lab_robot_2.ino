#include <Encoder.h>
#define encoder_a 2
#define encoder_b 3
volatile long encoder=0;
float theta = 0;



void setup() {
  Serial.begin(9600);
  pinMode(encoder_a,INPUT_PULLUP);
  pinMode(encoder_b,INPUT_PULLUP);
  attachInterrupt(0,encoderPinChang_A,RISING);
  
  

}
void encoderPinChang_A(){
  if((digitalRead(encoder_b))==HIGH){
  
  encoder++;
  }
  else{
    encoder--;
  }
}

void loop() {
  theta = (float(encoder)/float(2000)*360);
  Serial.println(theta);

  

}
