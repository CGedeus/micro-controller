// Carson Gedeus
// sketch_feb24d.ino
// Robots source-code for Arduino

//#define LED 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    char c = Serial.read();
    if(c == 0x30)
      digitalWrite(13, LOW);  //On switch; 0x30 is hexadecimal
    if(c == 0x31)
      digitalWrite(13, HIGH); //Off switch. 0x30 is hexadecimal
    Serial.write(c);  //ECHO Function
    if(c == 0x32){
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
    }
  }
}


