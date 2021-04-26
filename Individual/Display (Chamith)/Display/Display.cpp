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
int _co = 0;

Display::Display(int select_button, int back_button, int down_button, int up_button, int right_button, int left_button, int state )

{
    pinMode(select_button, INPUT); 
    pinMode(back_button, INPUT);
    pinMode(down_button, INPUT);
    pinMode(up_button, INPUT);
    pinMode(right_button, INPUT);
    pinMode(left_button, INPUT);


    _select = select_button;         //defining the variables for inside use
    _back = back_button;
    _down = down_button;
    _up = up_button;
    _right = right_button;
    _left = left_button;
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
}

void Display::select(){          //what to do when the user press select button
  if (_state == 0) {
    state_1();
  }
  else if (_state == 1){
    _state = 6;
    state_6();
  }
  else if (_state == 6){
    _state = 7;
    state_7();
  }
  else if (_state == 2){
    _state = 8;
    state_8();
  }
  else if (_state == 8){
    _state = 7;
    state_7();
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
  else if (_state == 6 or _state == 8) {
    if (_co == 0){                   //change a (time is in this form - ab:cd)
      if (_a != 2)  {_a = _a +1; }
      else { _a = 0; }
      lcd.clear();
      show();
      lcd.setCursor(0,1);
      lcd.print("Ok          Back");
      lcd.home();
      delay(500);
      _co = 0;
    }

    if (_co == 1){                  //change b (time is in this form - ab:cd)
      if (_a != 2){
        if (_b != 9) {_b = _b + 1; }
        else {_b = 0;}
        }
      else{
        if (_b != 4) {_b = _b + 1; }
        else {_b = 0;}
        }
      lcd.clear();
      show();
      lcd.setCursor(0,1);
      lcd.print("Ok          Back");
      lcd.setCursor(1,0);
      delay(500);
      _co = 1;
      }


    if (_co == 3){                   //change c (time is in this form - ab:cd)
      if (_c != 5)  {_c = _c +1; }
      else { _c = 0; }
      lcd.clear();
      show();
      lcd.setCursor(0,1);
      lcd.print("Ok          Back");
      lcd.setCursor(3,0);
      delay(500);
      _co = 3;
      }

    if (_co == 4){                   //change d (time is in this form - ab:cd)
      if (_d != 9)  {_d = _d +1; }
      else { _d = 0; }
      lcd.clear();
      show();
      lcd.setCursor(0,1);
      lcd.print("Ok          Back");
      lcd.setCursor(4,0);
      delay(500);
      _co = 4;
      }
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
  else if (_state == 6 or _state == 8) {
    if (_co == 0){                   //change a (time is in this form - ab:cd)
      if (_a != 0)  {_a = _a -1; }
      else { _a = 2; }
      lcd.clear();
      show();
      lcd.setCursor(0,1);
      lcd.print("Ok          Back");
      lcd.home();
      delay(500);
      _co = 0;
    }

    if (_co == 1){                  //change b (time is in this form - ab:cd)
      if (_a != 2){
        if (_b != 0) {_b = _b - 1; }
        else {_b = 9;}
        }
      else{
        if (_b != 0) {_b = _b - 1; }
        else {_b = 4;}
        }
      lcd.clear();
      show();
      lcd.setCursor(0,1);
      lcd.print("Ok          Back");
      lcd.setCursor(1,0);
      delay(500);
      _co = 1;
      }


    if (_co == 3){                   //change c (time is in this form - ab:cd)
      if (_c != 0)  {_c = _c -1; }
      else { _c = 5; }
      lcd.clear();
      show();
      lcd.setCursor(0,1);
      lcd.print("Ok          Back");
      lcd.setCursor(3,0);
      delay(500);
      _co = 3;
      }

    if (_co == 4){                   //change d (time is in this form - ab:cd)
      if (_d != 0)  {_d = _d -1; }
      else { _d = 9; }
      lcd.clear();
      show();
      lcd.setCursor(0,1);
      lcd.print("Ok          Back");
      lcd.setCursor(4,0);
      delay(500);
      _co = 4;
      }
    }
}


void Display::right(){              //right button can be used to move through a,b,c,d where time = ab:cd
  if (_co == 0){
  _co = 1;
  lcd.setCursor(1,0);
  delay(500);
  }

  else if (_co == 1){
  _co = 3;
  lcd.setCursor(3,0);
  delay(500);
  }

  else if (_co == 3){
  _co = 4;
  lcd.setCursor(4,0);
  delay(500);
  }
}

void Display::left(){              //left button can be used to move through a,b,c,d where time = ab:cd
  if (_co == 1){
  _co = 0;
  lcd.setCursor(0,0);
  delay(500);
  }

  else if (_co == 3){
  _co = 1;
  lcd.setCursor(1,0);
  delay(500);
  }

  else if (_co == 4){
  _co = 3;
  lcd.setCursor(3,0);
  delay(500);
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
  lcd.print("Existing Alarms");
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

void Display::state_6(){
  lcd.clear();
  show();
  lcd.setCursor(0,1);
  lcd.print("Ok          Back");
  lcd.home();
  lcd.blink();
  delay(500);
}

void Display::state_7(){
  lcd.noBlink();
  lcd.clear();
  lcd.home();
  _co = 0;
  lcd.print("Save "); lcd.print(_a); lcd.print(_b); lcd.print(":"); lcd.print(_c); lcd.print(_d); lcd.print(" ?");
  lcd.setCursor(0,1);
  lcd.print("Yes           No");
  delay(500);
}

void Display::state_8(){
  _a , _b , _c , _d = 0,0,0,0;
  state_6();
}

void Display::show(){
  lcd.clear();
  lcd.print(_a); lcd.print(_b); lcd.print(":"); lcd.print(_c); lcd.print(_d);
}
