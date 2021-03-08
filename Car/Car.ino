#include <Servo.h>
Servo servo;
int data;
int motor = 0;
float pos = 80;
float rot = 0.0;
float turn = 0.05;
int maxLeft = 120;
int maxRight = 40;
void setup() {
  Serial.begin(9600);
  servo.attach(3);
  pinMode (5, OUTPUT);
  pinMode (11, OUTPUT);
  delay(500);
}


void loop() {
  if(Serial.available() > 0){
    data = Serial.read()-48;
    Serial.println(data);
    if(data <= 9 && data >= 0)
      pos = maxLeft - (maxLeft-maxRight)*data/10;
    else if(data == 65)
      pos = maxRight;
    if(data == 18){
      analogWrite(5, 230);
      analogWrite(11, 0);
      Serial.println("onwards"); 
    }
    else if (data == 22){
      Serial.println("Back");
      analogWrite(11,230);
      analogWrite(5, 0);
    }
    else if(data == 35){
      analogWrite(5, 0);
      analogWrite(11, 0);
    }
  }
  servo.write(pos);
}
