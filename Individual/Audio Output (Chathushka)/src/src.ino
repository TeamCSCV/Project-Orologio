#include <Notes.h>
#include <Tone.h>



Tone tone1(8);

void setup() {
pinMode(6,OUTPUT);

}

void loop() {
  if (digitalRead(10)==HIGH){
    tone1.melody5();
  }
  else{
    digitalWrite(8,LOW);
    }
  }
