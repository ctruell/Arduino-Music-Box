#include <CircularLED.h>

//button D4, buzzer D8, circular led D5
int button = 4;
CircularLED circularLED(6,5);
unsigned int LED[24];
int buzzerPin = 8;

//carol of the bells length, beats, tones
//4 is a quater note, 8 an eight note, 2 a half note, 
//3 a dotted quarter note, and 1.5 a dotted half note
int length1 = 124;
int beats1[] = {4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,
8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,8,8,4,8,8,
8,8,4,8,8,8,8,4,8,8,4,8,8,8,8,8,8,8,8,4,4,8,8,8,8,8,8,8,8,4,4,4,8,8,
4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,1.5};
int tones1[] = {523, 494, 523, 440, 523, 494, 523, 440, 523, 494, 
523, 440, 523, 494, 523, 440, 523, 494, 523, 440, 523, 494, 523, 
440, 523, 494, 523, 440, 523, 494, 523, 440, 523, 494, 523, 440,
659, 587, 659, 523, 659, 587, 659, 523, 659, 587, 659, 523, 659, 
587, 659, 523, 880, 880, 880, 784, 698, 659, 659, 659, 587, 523,
587, 587, 587, 659, 587, 440, 440, 440, 440, 330, 370, 415, 440, 
494, 523, 587, 659, 587, 523, 330, 370, 415, 440, 494, 523, 587, 
659, 587, 523, 523, 494, 523, 440, 523, 494, 523, 440, 523, 494, 
523, 440, 523, 494, 523, 440, 523, 494, 523, 440, 523, 494, 523, 
440, 523, 494, 523, 440, 523, 494, 523, 440, 880};

//ode to joy length, beats, tones
int length3 = 62; //number of notes
int beats3[] = {4,4,4,4,4,4,4,4,4,4,4,4,3,8,2,4,4,4,4,4,4,4,4,4,4,4,
4,3,8,2,4,4,4,4,4,8,8,4,4,4,8,8,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,3,
8,2};
int tones3[] = {330, 330, 349, 392, 392, 349, 330, 294, 262, 262, 
  294, 330, 330, 294, 294, 165, 165, 175, 196, 196, 175, 165, 147,
  131, 131, 147, 165, 147, 131, 131, 294, 294, 330, 262, 294, 330, 349,
  330, 262, 294, 330, 349, 330, 294, 262, 294, 196, 330, 330, 349, 
  392, 392, 349, 330, 294, 262, 262, 294, 330, 294, 262, 262};

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length3; i++) {
    if (digitalRead(button) == HIGH) {
      break;
    }
    //play ode to joy and light notes
    tone(8, tones3[i], 1000 / beats3[i]);
    lightNote(i, 1000 / beats3[i], tones3);
    delay((1000 / beats3[i]) * 1.50);
  }
  if (digitalRead(button) == HIGH) {
    //stop for 2 seconds before starting carol of the bells
    delay(2000);
    for (int i = 0; i < length1; i++) {
      //play carol of the bells and light notes
      tone(8, tones1[i], 1000 / beats1[i]);
      lightNote(i, 1000 / beats1[i], tones1);
      delay((1000 / beats1[i]) * 1.50);
    }
    //stop for 2 seconds before starting ode to joy again
    delay(2000);
  }
}

void lightNote(int i, long duration, int arr[]) {
  //check which tone is played and light up the corresponding LED
  if (arr[i] == 131) { //C below middle C
    LED[0] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[0] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 147) { //D
    LED[1] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[1] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 165) { //E
    LED[2] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[2] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 175) { //F
    LED[3] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[3] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 196) { //G
    LED[4] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[4] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 220) { //A
    LED[5] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[5] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 247) { //B
    LED[6] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[6] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 262) { //Middle C
    LED[7] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[7] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 294) { //D
    LED[8] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[8] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 330) { //E
    LED[9] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[9] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 349 || arr[i] == 370) { //F and F#
    LED[10] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[10] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 392 || arr[i] == 415) { //G and G#
    LED[11] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[11] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 440) { //A
    LED[12] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[12] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 494) { //B
    LED[13] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[13] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 523) { //C above middle C
    LED[14] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[14] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 587) { //D
    LED[15] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[15] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 659) { //E
    LED[16] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[16] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 698) { //F
    LED[17] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[17] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 784) { //G
    LED[18] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[18] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 880) { //A
    LED[19] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[19] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else if (arr[i] == 988) { //B
    LED[20] = 0xff;
    circularLED.CircularLEDWrite(LED);
    delay(duration);
    LED[20] = 0;
    circularLED.CircularLEDWrite(LED);
  }
  else {
    //do nothing
  }
}
