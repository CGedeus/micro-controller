#include <Servo.h>

Servo myservo[6];

#define SERVO_TO_PIN(x) (x+2)

int pos = 5;  //Beginning Degree
int RotateDirection = 0;

void setup()
{
 Serial.begin(9600);
 for(int ServoNum = 0; ServoNum < 5; ServoNum++) //Creating for each cell in the myservo array
 {
   myservo[ServoNum].attach(SERVO_TO_PIN(ServoNum));  //attaches each pin to the program
 }
 Serial.println("Completed Setup");
}
int j;
void loop()
{
 pos += RotateDirection;
 
 if(pos >= 175)
 {
   RotateDirection = -10;
 }
 
 if(pos <=5)
 {
   RotateDirection = 10;
 }
 
 for(int ServoNum = 0; ServoNum <= 5; ServoNum++)
 {                                   
   myservo[ServoNum].write(pos);// tell servo to go to position in variable 'pos' 
   delay(15);                       // waits 15ms for the servo to reach the position 
   Serial.print("The angle of the servo");
   Serial.print(ServoNum);
   Serial.print(" is ");
   Serial.print(myservo[ServoNum].read());
   Serial.print('\n');
   //delay(500);  
 } 
} 

