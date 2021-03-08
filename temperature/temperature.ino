#include <ArduinoJson.h>

#include <string.h>
#define STRS 2
#define LETTERS 5
char foo[60];
char keys[4][15] = {"temperature", "time"};
char tmp[15] = "piping";
char when[15] = "never";
char *values[4] = {tmp, when};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  json(keys, values);  
  Serial.print(foo);
  
  
 
}
char *bar(){
  static char p[3] = "ab";
  return p;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /*Serial.print("x");
  Serial.print(analogRead(A0));
  Serial.print("x");*/
  delay(1000);
}
