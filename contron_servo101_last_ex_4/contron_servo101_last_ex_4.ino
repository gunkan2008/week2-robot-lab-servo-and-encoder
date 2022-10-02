#include <Encoder.h>
Encoder myEnc(2,3);
long oldPosition = -999;
long newPosition;

#define dirPin 9
#define stepPin 10
#define enPin 11
#define poten A0

unsigned long time_prev = 0;
int speed_stepper =10000;
int setpoint = 0, error =0 ,encoder = 0;
    

void setup() {
  Serial.begin(9600);
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  
  

}
void readEncoder(){
  newPosition = myEnc.read();
  if (newPosition != oldPosition){
    oldPosition = newPosition;
    encoder = float(newPosition)/8000*360;
    
  }
}
void step_drive_CW(){
  digitalWrite(dirPin,HIGH);
  digitalWrite(enPin,LOW);
  if(micros() >time_prev +speed_stepper) {
    digitalWrite(stepPin,HIGH);
    time_prev = micros();
  }
  digitalWrite(stepPin,LOW);
}
void step_drive_CCW(){
  digitalWrite(dirPin,LOW);
  digitalWrite(enPin,LOW);
  if(micros() >time_prev +speed_stepper) {
    digitalWrite(stepPin,HIGH);
    time_prev = micros();
  }
  digitalWrite(stepPin,LOW);
 
}
void loop(){
 setpoint = map(analogRead(poten),0,1023,0,360);
 readEncoder();
 error = setpoint- encoder;

 if (error > 1){
  step_drive_CW();
  
 }else if (error < 1){
  step_drive_CCW();
  
 }else{
  digitalWrite(enPin,LOW);
 }
 Serial.print("setpoint: ");
 Serial.print(setpoint);
 Serial.print("setpoint: ");
 Serial.print(encoder);
 Serial.print("setpoint: ");
 Serial.print(setpoint);

}
