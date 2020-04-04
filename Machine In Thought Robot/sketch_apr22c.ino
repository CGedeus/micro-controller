// Carson Gedeus
// sketch_apr22c.ino
// Robots source-code for Arduino

#include <Servo.h>

Servo firstServo;
Servo secondServo;
Servo earlyServos[5];

#define SERVO_TO_PIN(x) (x+2)

int pos = 0;
int ref = 0;

void setup() {
  Serial.begin(9600);
  for(int ServoNum=0; ServoNum<4; ServoNum++)
  {
    earlyServos[ServoNum].attach(SERVO_TO_PIN(ServoNum));
  }
  firstServo.attach(9);
  secondServo.attach(10);
}

void loop() {

  while(Serial.available())
  {
    char push = Serial.read();

    if(push == 0x77)   //w - move forwards
    {
      for(pos=0; pos<=180; pos+=1)
      {
        firstServo.write(pos);
      }
      for(pos=180; pos>=0; pos-=1)
      {
        secondServo.write(pos);
      }
    }
  
  
    else if(push == 0x73)  //s - move backwards
    {
      for(pos=180; pos>=0; pos-=1)
      {
        firstServo.write(pos);
      }
      for(pos=0; pos<180; pos+=1)
      {
        secondServo.write(pos);
      }
    }
  
  
  
  
  
    else if(push == 0x61)   //a - Go left
    {
      for(pos=0; pos<=180; pos+=1)
      {
        firstServo.write(pos);
        secondServo.write(pos);
      }
    }
    
  
    else if(push == 0x64)   //d - Go right
    {
      for(pos=180; pos>=0; pos-=1)
      {
        firstServo.write(pos);
        secondServo.write(pos);
      }
    }




    else if(push == 0x6A)   //J
    {
      earlyServos[5].write(90-ref);
    }

    else if(push == 0x6B)   //K
    {
      earlyServos[5].write(ref-90);
    }


  
  
    else if(push == 0x70)   //p - stop forever
    {
      firstServo.detach();
      secondServo.detach();
    }


    for(int ServoNum=0; ServoNum<=4; ServoNum++)
    {
      earlyServos[ServoNum].write(conv);
    }

  }
}



