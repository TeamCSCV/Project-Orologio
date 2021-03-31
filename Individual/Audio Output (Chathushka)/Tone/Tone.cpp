#include "Arduino.h"
#include "Tone.h"
#include "Notes.h"



Tone::Tone(int pin)
{
    pinMode(pin,OUTPUT);
    _pin=pin;
}

void Tone::melody1()
{
  
    int melody[] = {
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5
 };

int noteDurations[] = {
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  };
  
  int length = sizeof(noteDurations)/sizeof(noteDurations[0]);
  for (int currentNote=0; currentNote<length;currentNote++)
  {
    int noteDuration = 750 / noteDurations[currentNote];
    tone(_pin,melody[currentNote],noteDuration);
    int pauseBetweenNotes= noteDuration*1.30;
    delay (pauseBetweenNotes);
    noTone(_pin);
  }

delay(1000);
}

void Tone::melody2()
{
   int melody[] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4,
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4,
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4,
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4,
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4,
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4,
    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,
    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4};

int noteDurations[] = {
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 2,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 2,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,
    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 2,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 2,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 2,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,
    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 2,
    4, 8, 2, 4, 8, 2,
    8, 8, 8, 8, 8, 8, 8, 8, 2,
    4, 8, 2, 4, 8, 2,
    8, 8, 8, 8, 8, 1,
    4, 8, 2, 4, 8, 2,
    8, 8, 8, 8, 8, 8, 8, 8, 2,
    4, 8, 2, 4, 8, 2,
    8, 8, 8, 8, 8, 1};
  
  int length = sizeof(noteDurations)/sizeof(noteDurations[0]);

  for (int currentNote=0; currentNote<length;currentNote++)
  {
    int noteDuration = 750 / noteDurations[currentNote];
    tone(_pin,melody[currentNote],noteDuration);
    int pauseBetweenNotes= noteDuration*1.30;
    delay (pauseBetweenNotes);
    noTone(_pin);
  }
 delay(1000);
}

void Tone::melody3()
{
   int melody[] = {
     NOTE_G4,
NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_D4,
NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
NOTE_G3,NOTE_AS3,NOTE_F4,NOTE_AS3,
NOTE_AS3,NOTE_D4,NOTE_F4,NOTE_AS3,
NOTE_DS4,NOTE_D4,NOTE_GS3,NOTE_F3,
NOTE_GS3,NOTE_G3,NOTE_C4,NOTE_F3,
NOTE_GS3,NOTE_G3,NOTE_GS3,NOTE_F3,
NOTE_GS3,NOTE_G3,NOTE_C4,NOTE_F3,
NOTE_GS3,NOTE_G4,NOTE_C4,NOTE_DS4,
NOTE_F4,NOTE_G4,NOTE_C4,NOTE_DS4,
NOTE_F4,NOTE_D4,NOTE_G3,NOTE_AS3,
NOTE_C4,NOTE_D4,NOTE_G3,NOTE_AS3,
NOTE_C4,NOTE_D4,NOTE_G3,NOTE_AS3,
NOTE_C4,NOTE_D4,NOTE_G3,NOTE_AS3,
NOTE_F4,NOTE_AS3,NOTE_AS3,NOTE_D4,
NOTE_F4,NOTE_AS3,NOTE_DS4,NOTE_D4,
NOTE_GS3,NOTE_F3,NOTE_GS3,NOTE_G3,
NOTE_C4,NOTE_F3,NOTE_GS3,NOTE_G3,
NOTE_GS3,NOTE_F3,NOTE_GS3,NOTE_G3,
NOTE_C4,NOTE_F3,NOTE_GS3
};

int noteDurations[] = {
12,12,24,24,
12,12,24,24,
12,12,24,24,
12,12,24,24,
12,12,24,24,
12,12,24,24,
12,12,24,24,
12,12,24,24,
4,4,24,24,
6,6,24,24,
12,12,24,24,
12,12,24,24,
12,12,24,24,
12,12,12,4,
4,24,24,6,
6,24,24,12,
12,24,24,12,
12,24,24,12,
12,24,24,12,
12,12,4,4,
24,24,6,6,
24,24,12,12,
24,24,12,12,
24,24,12,12,
24,24,12,12,
12,4,4,24,
24,6,6,24,
24,12,12,24,
24,12,12,24,
24,12,12,24,
24,12,12,12
};
  
  int length = sizeof(noteDurations)/sizeof(noteDurations[0]);

  for (int currentNote=0; currentNote<length;currentNote++)
  {
    int noteDuration = 2750 / noteDurations[currentNote];
    tone(_pin,melody[currentNote],noteDuration);
    int pauseBetweenNotes= noteDuration*1.30;
    delay (pauseBetweenNotes);
    noTone(_pin);
  }
 delay(1000);
}


void Tone::melody4()
{
    int melody[] = {
  NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,0
 };

int noteDurations[] = {
  4,4,4,4,1
  };
  
  int length = sizeof(noteDurations)/sizeof(noteDurations[0]);
  int i=0;
  while (i<10){
  for (int currentNote=0; currentNote<length;currentNote++)
  {
    int noteDuration = 250 / noteDurations[currentNote];
    tone(_pin,melody[currentNote],noteDuration);
    int pauseBetweenNotes= noteDuration*2;
    delay (pauseBetweenNotes);
    noTone(_pin);
  }
  i++;
  }

delay(1000);
}


void Tone::melody5()
{
    int melody[] = {
  NOTE_C3,NOTE_G3,NOTE_G2,NOTE_G3,
  NOTE_C3,NOTE_G3,NOTE_G2,NOTE_G3,
  NOTE_C4,NOTE_G4,
  NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_GS4,
  NOTE_G4,NOTE_F4,NOTE_C5,NOTE_C5,
  NOTE_F4,NOTE_C5,NOTE_C5,NOTE_B4,
  NOTE_C5,NOTE_D5,NOTE_C5,NOTE_DS5,
  NOTE_DS5,NOTE_G5,NOTE_C5,NOTE_C5,
  NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_C5,
  NOTE_F5,NOTE_C5,0,0,
  0,NOTE_C5,NOTE_D5,NOTE_DS5,
  NOTE_DS5,NOTE_F5,NOTE_D5,NOTE_D5,
  NOTE_DS5,NOTE_C5,NOTE_C5,NOTE_D5,
  NOTE_B4,NOTE_GS4,NOTE_G4,NOTE_C5,0,
  NOTE_G5,NOTE_C5,NOTE_C5,
  NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_C5,
  NOTE_F5,NOTE_C5,0,0,
  0,NOTE_C5,NOTE_D5,NOTE_DS5,
  NOTE_DS5,NOTE_F5,NOTE_D5,NOTE_D5,
  NOTE_DS5,NOTE_C5,NOTE_C5,NOTE_D5,
  NOTE_B4,NOTE_GS4,NOTE_G4,NOTE_C5
  
 };
 
 

int noteDurations[] = {
  12,12,12,12,
  12,12,12,12,
  12,6,
  12,24,24,6,
  12,12,4,3,
  12,6,12,24,
  24,6,12,3,
  3,12,6,12,
  12,12,12,12,
  12,12,6,6,
  12,24,24,12,
  24,24,12,24,
  24,12,24,24,
  12,24,24,3,3,
  12,6,12,
  12,12,12,12,
  12,12,6,6,
  12,24,24,12,
  24,24,12,24,
  24,12,24,24,
  12,24,24,3
  };
 
  int length = sizeof(noteDurations)/sizeof(noteDurations[0]);

  for (int currentNote=0; currentNote<length;currentNote++)
  {
    int noteDuration = 750*3 / noteDurations[currentNote];
    tone(_pin,melody[currentNote],noteDuration);
    int pauseBetweenNotes= noteDuration*1.30;
    delay (pauseBetweenNotes);
    noTone(_pin);
  }

delay(1000);
}