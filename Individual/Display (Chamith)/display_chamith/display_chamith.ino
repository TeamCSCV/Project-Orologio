#include <Display.h>  // include my library

int select_button = 13;
int back_button = 10;
int down_button = 8;
int up_button = 9;  
int right_button = 7;
int left_button = 6;    //declare my buttons
 
int state = 0;  //the time displaying mode(initial state)

Display display(select_button, back_button, down_button, up_button, right_button, left_button, state);   //providing data to my class
 

void setup() {
  display.start();  //start the clock
}  

void loop() {
  int select_state = digitalRead(select_button);
  if (select_state == HIGH){    //user press the select button
    display.select();
   }
   
  int back_state = digitalRead(back_button);
  if (back_state == HIGH){       //user press the back button
    display.back();
  }
  
  int down_state = digitalRead(down_button);
  if (down_state == HIGH){      //user press the down button
    display.down();
  }

  int up_state = digitalRead(up_button);
  if (up_state == HIGH){       //user press the up button
    display.up();
  }

  int right_state = digitalRead(right_button);
  if (right_state == HIGH){
    display.right();
  }

  int left_state = digitalRead(left_button);
  if (left_state == HIGH){
    display.left();
  }
}
