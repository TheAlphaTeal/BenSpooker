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
#define SPKR_PIN 7

#define RS 8
#define EN 9
#define D4 10
#define D5 11
#define D6 12
#define D7 13

// Variables
bool triggered;
const int durationLimit = 7000;
long duration;
int distance;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
int leds[] = {R_PIN, W_PIN, B_PIN};
int ledssize = sizeof(leds)/sizeof(*leds);
int currentled;

int length = 28; // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
int tempo = 150;

void setup() { 
  triggered = false;
  currentled = 0;

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(R_PIN, OUTPUT);
  pinMode(W_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(BKLT_PIN, OUTPUT);
  pinMode(SPKR_PIN, OUTPUT);

  lcd.begin(16, 2);
  
  // "Exit" delay. So you don't set off the "alarm" accidentally
  delay(5000);
}

void loop() {
  // Do nothing until Ultrasonic sensor is triggered
  while(!triggered) {
    delay(100);
    triggered = checkProximity();

    if(triggered){
      //triggered = true;
      writeLCD();
      digitalWrite(BUZZER_PIN, HIGH);
      delay(2000);
      digitalWrite(BUZZER_PIN, LOW);
    }
  }

  // Play Happy birthday
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }

   // pause between notes
   delay(tempo);
   digitalWrite(leds[currentled], LOW);
   digitalWrite(leds[(currentled+1)%ledssize], HIGH);
   currentled = (currentled+1)%ledssize;
  }
}

bool checkProximity() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    float resp = pulseInLong(ECHO_PIN, HIGH);

    if(resp < durationLimit && resp != 0) {
      return true;
    } else {
      return false;
    }
} 

void writeLCD() {
  lcd.print("HAPPY BIRTHDAY");
  lcd.setCursor(0,1);
  lcd.print("BEN!!!!!!!!!!!!");
  digitalWrite(BKLT_PIN, HIGH);
}

void playTone(int tone, int toneDuration) {
  for (long i = 0; i < toneDuration * 1000L; i += tone * 2) {
    digitalWrite(SPKR_PIN, HIGH);
    delayMicroseconds(tone);
    digitalWrite(SPKR_PIN, LOW);
    delayMicroseconds(tone);
    }
}

void playNote(char note, int noteDuration) {
  char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           
                  'c', 'd', 'e', 'f', 'g', 'a', 'b',
                  'x', 'y' };

  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
                  956,  834,  765,  593,  468,  346,  224,
                  655 , 715 };

  int SPEE = 5;

  // play the tone corresponding to the note name
  for (int i = 0; i < 17; i++) {
    if (names[i] == note) {
      int newduration = noteDuration/SPEE;
      playTone(tones[i], newduration);
    }
  }
}
