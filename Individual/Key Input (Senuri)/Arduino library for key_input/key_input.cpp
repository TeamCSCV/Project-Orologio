#include "Arduino.h"
#include "key_input.h"

key_input::key_input(int pin)
{
  for (int _pin=pin;_pin<=6; _pin++)
    pinMode(_pin, OUTPUT);
  for (int _pin=pin+4; _pin<=9; _pin++)
    pinMode(_pin, INPUT);
  for (int _pin=pin+7; _pin<=13;_pin++)
    pinMode(_pin, OUTPUT);
}

int key_input::keyInput() {
    int rows[4]={3,4,5,6};
    int columns[3]={7,8,9};
    int keys[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};
    
    for (int r=0; r<=3; r++){ // set all row pins to HIGH
      digitalWrite(rows[r],HIGH);
    }
    for (int r=0; r<=3; r++){
       digitalWrite(rows[r],LOW); // set the current row pin to LOW
       
      for (int c=0; c<=2; c++){
        digitalWrite(columns[c],HIGH); // set the column pins to HIGH initially 
        if ((digitalRead(columns[c])==0) and (digitalRead(rows[r])==0)) { // while the current row pin is LOW check whether if any column pin is LOW
          int pressed=keys[r][c]; // obtain the pressed key
          if (pressed!=42 and pressed!=35){ // if a number is pressed
            return pressed;} // return the pressed key
          else{ // if '*' or '#' is pressed
            return 100;}
          } 
        }
      digitalWrite(rows[r],HIGH); // set the current pin again to HIGH
      }    
      return 100; // if a key is not pressed return 100 
}

void led(){
   int key= keyInput(); // obtaining the pressed key byt callig the keyInput function
   if (key==100){   // if a key is not pressed turn off all the LEDs
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
     } 
   else{          
    int binary[4]={0,0,0,0}; 
    for (int i=3; i>=0 ;i--){  // convert the pressed key from decimal to binary
      binary[i]=key%2;
      key=key/2; 
      for (int i=0; i<=3; i++){ // turn on or off the 4 LEDs according to the binary number
        if (binary[i]==0){
          digitalWrite(i+10,LOW);
          }
        else{
          digitalWrite(i+10,HIGH);
            }
           }
         }
      }    
   }