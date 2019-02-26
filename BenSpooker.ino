// File: BenSpooker.ino
// Programmer: Joey Gore
// Date: 2019-02-21
// Description: Utilize motion sensing to spook Ben on his
// birthday

#include <LiquidCrystal.h>

// Globals
// Pin definitions
#define TRIG_PIN 0
#define ECHO_PIN 1
#define BUZZER_PIN 2
#define R_PIN 3
#define W_PIN 4
#define B_PIN 5
#define BKLT_PIN 6

#define RS 8
#define EN 9
#define D4 10
#define D5 11
#define D6 12
#define D7 13

// Variables
bool triggered;
long duration;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  triggered = false;

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(R_PIN, OUTPUT);
  pinMode(W_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(BKLT_PIN, OUTPUT);

  lcd.begin(16, 2);
  
  // "Exit" delay. So you don't set off the "alarm" accidentally
  //delay(5000);
}

void loop() {
  // Do nothing until Ultrasonic sensor is triggered
  while(!triggered) {
    delay(500);
    
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);

    if(duration < 1000){
      triggered = true;
      writeLCD();
      digitalWrite(BUZZER_PIN, HIGH);
    }
  }

  //digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(R_PIN, LOW);
  digitalWrite(W_PIN, HIGH);
  delay(500);

  //digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(W_PIN, LOW);
  digitalWrite(B_PIN, HIGH);
  delay(500);

  //digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(B_PIN, LOW);
  digitalWrite(R_PIN, HIGH);
  delay(500);
}

void writeLCD() {
  lcd.print("HAPPY BIRTHDAY");
  lcd.setCursor(0,1);
  lcd.print("BEN!!!!!!!!!!!!");
  digitalWrite(BKLT_PIN, HIGH);
}

