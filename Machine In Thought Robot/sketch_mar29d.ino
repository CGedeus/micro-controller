//Carson Gedeus - March 29, 2016
//Second servo motor running wirelessly via XCTU
//Conveyor Belt
#include <Servo.h>

Servo MyServo[12];

int pos = 0;  //variable for default position of a variable
int theServo = 0;

#define SERVO_TO_PIN(x) (x+2)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //MyServo.attach(9);  //attached to servo via pin 9 on arduino

  for(theServo=0; theServo<11; theServo++)
  {
    MyServo[theServo].attach(SERVO_TO_PIN(theServo));
  }
}

void loop() {
    // put your main code here, to run repeatedly:
    while(Serial.available()){
  
    char button = Serial.read();
  
      if(button == 0x61)
        for(pos = 0; pos <= 180; pos +=1)   //BACKWARD
        {
        MyServo[theServo].write(pos);
        //delay(15);
        }


     if(button == 0x64)
       for(pos = 180; pos >= 0; pos -=1)    //FORWARD
       {
       MyServo[theServo].write(pos);
       //delay(15);
       }


     if(button == 0x73) //Press "s" to stop servo motor COMPLETELY
      MyServo[theServo].detach();


      for(theServo=0; theServo<11; theServo++)
      {
        MyServo[theServo].write(pos);
        delay(15);
      }
      Serial.write(button);
  }
}



