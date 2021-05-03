#include <Tone.h>

Tone alarmTone(5,6); //To create an instance of the Tone class called alarmTone , Enter the pin numbers of the buzzer/speaker and the button.

int i; 

void setup() {
  i=1;  // Initial value, to change the melody
  delay(500);

}

void loop() {

  alarmTone.play(i); //To play ith melody
  i++; 
  delay(500);
    
  if(i>5){i=1;} 
  
  }
   
