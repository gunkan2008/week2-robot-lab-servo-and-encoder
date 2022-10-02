#include <Encoder.h>
#define dirPin 9
#define stepPin 10
#define enPin 11
unsigned long time_prev = 0;
int speed_stepper =5000;



void setup() {
  Serial.begin(9600);
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  
  

}
void encoderPinChang_A(){
  digitalWrite(dirPin,HIGH);
  digitalWrite(enPin,LOW);
  if(micros() >time_prev +speed_stepper) {
    digitalWrite(stepPin,HIGH);
    time_prev = micros();
  }
  digitalWrite(stepPin,LOW);
  

}
