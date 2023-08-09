#include <Arduino.h>


void setup() {
  Serial.begin(9600);
  //pinMode(9,OUTPUT);
  DDRB = B00000010;
  PORTB = B00000000;
}

void loop() {
  //digitalWrite(9, HIGH);
  PORTB = PORTB | B00000010;
  delay(500);
  //digitalWrite(9, LOW);
  PORTB =  ~(PORTB ^ B00000000);
  delay(500);
}