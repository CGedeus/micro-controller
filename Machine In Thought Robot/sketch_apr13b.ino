// Carson Gedeus
// sketch_apr13b.ino
// Robots source-code for Arduino

#include <Servo.h>

#define leftMotorPin 11
#define rightMotorPin 10

//Servo firstServo;
//Servo secondServo;
//Servo earlyServos[5];

//#define SERVO_TO_PIN(x) (x+2)

int pos = 0;
//int ref = 0;

void setup() {

  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
  
  Serial.begin(9600);
  /*  
    for(int ServoNum=0; ServoNum<4; ServoNum++)
    {
      earlyServos[ServoNum].attach(SERVO_TO_PIN(ServoNum));
    }
    */
  //  firstServo.attach(9);
  //  secondServo.attach(10);
}

void loop() {

  while(Serial.available())
  {
    char push = Serial.read();

    
    if(push == 0x77)   //w - move forwards
    { 
      analogWrite(leftMotorPin, 100);   //will make it move forwards
      analogWrite(rightMotorPin, 250);
      /*for(pos=0; pos<=180; pos+=1)
      {
        firstServo.write(pos);
      }
      for(pos=180; pos>=0; pos-=1)
      {
        secondServo.write(pos);
      }*/
    }
  
    if(push == 0x73)  //s - move backwards
    {
      analogWrite(leftMotorPin, 250);   //will make it move backwards
      analogWrite(rightMotorPin, 100);
      
      /*for(pos=180; pos>=0; pos-=1)
      {
        firstServo.write(pos);
      }
      for(pos=0; pos<180; pos+=1)
      {
        secondServo.write(pos);
      }*/
    }
  
    if(push == 0x61)   //a - Go left
    {
      analogWrite(leftMotorPin, 100);
      analogWrite(rightMotorPin, 100);
      /*
      for(pos=0; pos<=180; pos+=1)
      {
        firstServo.write(pos);
        secondServo.write(pos);
      }
      */
    }

    if(push == 0x64)   //d - Go right
    {
      analogWrite(leftMotorPin, 250);
      analogWrite(rightMotorPin, 250);
    /*
      for(pos=180; pos>=0; pos-=1)
      {
        firstServo.write(pos);
        secondServo.write(pos);
      }
    */
    }
/*
    case(0x6A):   //J
    {
      earlyServos[5].write(90-ref);
    }

    case(0x6B):   //K
    {
      earlyServos[5].write(ref-90);
    }
    break;
*/
    if(push == 0x70)   //p - stop forever
    {
      analogWrite(leftMotorPin, 255);
      analogWrite(rightMotorPin, 0);
      //firstServo.detach();
    }

    Serial.write(push);
      /*
      for(int ServoNum=0; ServoNum<=4; ServoNum++)
      {
        earlyServos[ServoNum].write(ServoNum);
      }
      */
  }
}