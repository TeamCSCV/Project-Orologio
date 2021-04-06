/*
  Display.cpp - Library for Alarm clock Display.
  Created by Chamith Dilshan Ranathunga, 06-04-2021
*/

#include "Arduino.h"
#include "Display.h"
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Display::Display(int select_button, int back_button, int down_button, int up_button, int state )

{
    pinMode(select_button, INPUT); 
    pinMode(back_button, INPUT);
    pinMode(down_button, INPUT);
    pinMode(up_button, INPUT);

    _select = select_button;
    _back = back_button;
    _down = down_button;
    _up = up_button;
    _state = state;

    
}

void Display::start(){
    lcd.begin(16, 2);
    lcd.print("Welcome!");
    delay(2000);
    time();
}

void Display::time(){
  lcd.clear();
  lcd.print("Time");
}

void Display::select(){
    if (_state == 0) {
    _state = 1;
    lcd.clear();
    lcd.print("1)Set Alarms");
    lcd.setCursor(0, 1);
    lcd.print("2)Set Time");
  }
}

void Display::back(){
    if (_state == 1 or _state ==2 or _state == 3) {
    _state = 0;
    time();
  }
}

void Display::up(){
    if (_state ==2) {
    _state = 1;
    lcd.clear();
    lcd.print("1)Set Alarms");
    lcd.setCursor(0, 1);
    lcd.print("2)Set Time");
    delay(500);
  }
  else if (_state == 3) {
    _state =2;
    lcd.clear();
    lcd.print("3)Existing Alarms");
    lcd.setCursor(0, 1);
    lcd.print("4)Change alarms");
    delay(500);
  }
}

void Display::down(){
    if (_state == 1) {
    _state =2;
    lcd.clear();
    lcd.print("3)Existing Alarms");
    lcd.setCursor(0, 1);
    lcd.print("4)Change alarms");
    delay(500);
  }
  else if (_state ==2) {
    _state = 3;
    lcd.clear();
    lcd.print("5)Factory Reset");
    delay(500);
  }
}

