#include <avr/sleep.h>

bool marioFlag = false;
bool boopFlag = false;

int tonePin = 5;
float tF;

void setup() {
  //CLKPR = 0x80;
  //CLKPR = 0x01;
  for(int i = 0; i < 20; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  tF = pow(2, CLKPR);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(tonePin, OUTPUT);
  tone(tonePin, 440 * tF); 
  delay(1000 / tF);
  noTone(tonePin);
  attachInterrupt(digitalPinToInterrupt(2), [](){
    marioFlag = true;  
  }, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), [](){
    boopFlag = true;
  }, FALLING);
}
void loop() {
  delay(1000);                                       
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_cpu();
  Serial.println("woke");
  if(marioFlag){
    Serial.println("mario");
    mario();
    marioFlag = false;
  }
  else if(boopFlag){
    Serial.println("boop");
    boop();
    boopFlag = false;
  }
  
  delay(1);
}
void boop() {
  float factor = 0.4;
  float tuning = 1;
  tuning = tuning * tF;
  factor /= tF;
  tone(tonePin, 400 * tuning);
  delay(500 * factor);
  tone(tonePin, 600 * tuning);
  delay(350 * factor);
  noTone(tonePin);
}
void song() {
  float factor = 2;
  float tuning = 0.7;
  tuning = tuning * tF;
  factor /= tF;
  delay(0 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (75 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (74 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (73 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (74 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (73 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (72 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (71 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (70 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (69 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (70 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (72 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (71 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (70 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (71 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (70 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (69 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (68 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (67 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (66 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (67 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (70 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (68 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (68 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (64 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (65 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (70 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (68 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (68 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (64 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (65 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (62 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (63 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (64 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (65 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (66 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (67 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (68 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (69 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (70 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (71 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (72 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (73 - 69) / 12.0)));
  delay(17 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (72 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);
  delay(31 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (70 - 69) / 12.0)));
  delay(65 * factor);
  noTone(tonePin);

}

void mario() {

  float factor = 1.3;
  float tuning = 0.5;
  tuning = tuning * tF;
  factor /= tF;

  delay(0 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (76 - 69) / 12.0)));
  delay(98 * factor);
  noTone(tonePin);
  delay(0 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (76 - 69) / 12.0)));
  delay(96 * factor);
  noTone(tonePin);
  delay(95 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (76 - 69) / 12.0)));
  delay(94 * factor);
  noTone(tonePin);
  delay(99 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (72 - 69) / 12.0)));
  delay(96 * factor);
  noTone(tonePin);
  delay(0 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (76 - 69) / 12.0)));
  delay(94 * factor);
  noTone(tonePin);
  delay(96 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (79 - 69) / 12.0)));
  delay(98 * factor);
  noTone(tonePin);
  delay(286 * factor);
  tone(tonePin, round(tuning * 440 * pow(2, (67 - 69) / 12.0)));
  delay(145 * factor);
  noTone(tonePin);


}
