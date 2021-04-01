#include <Notes.h>
#include <Tone.h>



Tone alarmTone(8,4);

int i=1;

void setup() {
  i=1;
  delay(500);

}

void loop() {

  alarmTone.play(i);
  i++;
  delay(500);
    
  if(i>5){i=1;}
    
    
    
    
  }
