# BenSpooker
Arduino code for project to spook Ben on his birthday

## Hardware used
- Arduino Uno rev.3, although any compatible Arduino or clone should work
- 2 red, white, and blue LEDs
- 3 220Ω resistors
- HC-SR04 ultrasonic distance sensor
- 16x2 HD44780 LCD screen
- 10k potentiometer
- Active buzzer
- Passive buzzer
- Recommended
  - Breadboard
  - Jumper cables
  - Other quick prototyping tools, etc.

## What it do
As soon as a set distance is detected by the ultrasonic sensor, A 2s tone plays from the active buzzer. This is designed to spook the Ben. After that, "HAPPY BIRTHDAY BEN!!!!!!!!!!!!" is printed to the LCD screen, the Happy Birthday song plays on the passive buzzer, and the LEDs cycle red, white, and blue in tune with the song. Plays until the Arduino is reset or powered off.

## Success!
The system was deployed on 2019-02-28 at approximately 1:00 AM. Ben entered his room before 2:00AM, and was sufficiently spooked by the DrakeBot (The breadboard and Arduino were attached to a cardboard cutout of Drake). A small offering of a pint of gin was placed at the feet of DrakeBot to mitigate Ben's anger.

In the wise words of Ben McMillin,

> "FUCK!"

## Photos and video
### DrakeBot in action, after triggering
![DrakeBot in action](https://imgur.com/ikR37Ho.jpg "DrakeBot in action")

### Better lighting to see all components
![Components](https://imgur.com/WQu0Bfb.jpg "Components")

### Video
[Link to video of what Ben saw!](https://twitter.com/AlphaTeal/status/1101280600932134912) I probably should have had the lights off in this video for better effect though...

## Sources
The code to play "Happy Birthday" on the passive buzzer is not my own. I copied it from [this project on the Arduino Project Hub](https://create.arduino.cc/projecthub/trduunze/piezo-happy-birthday-7ea362) that is licensed under the GNU GPL3+