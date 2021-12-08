#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Soundbites.h"
#include "Vocab_US_TI99.h"
#include "Vocab_US_Acorn.h"

#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"
// These are 'flexible' lines that can be changed
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8 // RST can be set to -1 if you tie it to Arduino's reset

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);


//THE SCREWDRIVER
Talkie voice;

const int button1 = A0;
const int button2 = A1;
const int button3 = A2;
const int button4 = A3;
const int button5 = A4;
const int button6 = A5;
int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;
int state5 = 0;
int state6 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  Serial.println("Starting");

  tft.begin();
  tft.setRotation(1);
  testText();
  

}
void loop() {
  state1 = digitalRead(button1);
  state2 = digitalRead(button2);
  state3 = digitalRead(button3);
  state4 = digitalRead(button4);
  state5 = digitalRead(button5);
  state6 = digitalRead(button6);

  
  if (state1 == HIGH) {
    Serial.println("button1");
    voice.say(sp2_NUMBER);
    voice.say(sp2_ONE);
    //delay(1000);
    return;
  }

  if (state2 == HIGH) {
    Serial.println("button2");
    voice.say(sp2_NUMBER);
    voice.say(sp2_TWO);
    //delay(1000);
    return;
  }

  if (state3 == HIGH) {
    Serial.println("button3");
    voice.say(spHMMM_BEER);
    //delay(1000);
    return;
  }

  if (state4 == HIGH) {
    Serial.println("button4");
    voice.say(sp2_RIGHT);
    voice.say(sp2_ON);
    //delay(1000);
    return;
  }

  if (state5 == HIGH) {
    Serial.println("button5");
    voice.say(spa_YES);
    //delay(1000);
    return;
  }
  
  if (state6 == HIGH) {
    Serial.println("button6");
    voice.say(spa_NO);
    //delay(1000);
    return;
  }
}

unsigned long testText() {
  tft.fillScreen(HX8357_BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(HX8357_GREEN);
  tft.setTextSize(3);
  tft.println("\nButton 1 = NUMBER 1\n");
  tft.println("Button 2 = NUMBER 2\n"); 
  tft.println("Button 3 = HMMM BEER\n");
  tft.println("Button 4 = RIGHT ON!\n");
  tft.println("Button 5 = YES\n");
  tft.println("Button 6 = NO"); 
}
