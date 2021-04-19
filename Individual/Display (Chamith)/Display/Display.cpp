/*
  Display.cpp - Library for Alarm clock Display.
  Created by Chamith Dilshan Ranathunga, 06-04-2021
*/

#include "Arduino.h"
#include "Display.h"
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int _a=0 , _b=0 , _c=0 , _d=0;   //assume that the time is in ab:cd format
int _col = 0, _row =0;    //defines the place of cursor


Display::Display(int select_button, int back_button, int down_button, int up_button, int state )

{
    pinMode(select_button, INPUT); 
    pinMode(back_button, INPUT);
    pinMode(down_button, INPUT);
    pinMode(up_button, INPUT);

    _select = select_button;         //defining the variables for inside use
    _back = back_button;
    _down = down_button;
    _up = up_button;
    _state = state;  
}


void Display::start(){             //welcome message
    lcd.begin(16, 2);
    lcd.print("Welcome.");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.clear();
    time();
    delay(500);
}

void Display::time(){             //display the current time
  lcd.clear();
  lcd.print("Time");
  delay(500);
}

void Display::select(){          //what to do when the user press select button
    if (_state == 0) {
    state_1();
  }
    else if (_state == 1){
      _state = 6;
      lcd.clear();
      show();
      lcd.home();
      lcd.blink();
      delay(500);
    }
}
 
void Display::back(){            //what to do when user press the back button
    if (_state == 1 or _state ==2 or _state == 3 or _state == 4 or _state == 5) {           
    _state = 0;
    time();
    delay(500);
  }
}

void Display::up(){              //what to do when the user presss the up button
    if (_state == 1) {
      state_5();    
  }
  else if (_state == 2) {
      state_1();
  }
  else if (_state == 3) {
      state_2();
  }
  else if (_state == 4) {
      state_3();
  }
  else if (_state == 5) {
      state_4();
  }
  else if (_state == 6) {
      if (_a != 2){
        _a = _a +1;
      }
      else {
        _a = 0;
      }
      show();
      lcd.setCursor(_col,_row);
      delay(250);
  }
}

void Display::down(){         //what to do when user pressed the down button
    if (_state == 1) {
    state_2();
  }
  else if (_state == 2) {
    state_3();
  }
  else if (_state == 3) {
    state_4();
  }
  else if (_state == 4) {
    state_5();
  }
  else if (_state == 5) {
    state_1();
  }
}

void Display::state_1(){
  _state = 1;
  lcd.clear();
  lcd.print("Set Alarm");
  delay(500);
}

void Display::state_2(){
  _state = 2;
  lcd.clear();
  lcd.print("Set Time");
  delay(500);
}

void Display::state_3(){
  _state = 3;
  lcd.clear();
  lcd.print("Existing");
  lcd.setCursor(0,1);
  lcd.print("Alarms");
  delay(500);
}

void Display::state_4(){
  _state = 4;
  lcd.clear();
  lcd.print("Change Alarms");
  delay(500);
}

void Display::state_5(){
  _state = 5;
  lcd.clear();
  lcd.print("Factory Reset");
  delay(500);
}

void Display::show(){
  lcd.clear();
  lcd.print(_a); lcd.print(_b); lcd.print(":"); lcd.print(_c); lcd.print(_d);
}