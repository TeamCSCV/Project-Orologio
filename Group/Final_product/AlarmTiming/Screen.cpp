/*
 * Screen.cpp
 *
 * Created: 5/8/2021
 *  Author: Chamith Ranathunga
 *  .cpp file for the library screen
 */ 


#include <avr/io.h>              //#include the header files I want
#include <util/delay.h>
#include "Screen.h"           


#define F_CPU 1000000UL

#define LCD_Dir DDRD           //defines some variables that the code using
#define LCD_Port PORTD
#define RS PD0
#define EN PD1               

int _state = 0;          //_state represents a numerical index given to the screen massage
int _co =0;   
int _a=0 , _b=0 , _c=0 , _d=0;   //assume that the Time is in ab:cd format

//this command is use to send a command to the LCD as an unsigned char
void Screen::LCD_Command(unsigned char cmnd)      
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
	LCD_Port &= ~ (1<<RS);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void Screen::LCD_Char(unsigned char data)
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
	LCD_Port |= (1<<RS);		//RS = 1
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (data << 4);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}


//function to initialize the LCD dispay
void Screen::LCD_Init(void)
{
	LCD_Dir = 0xFF;			//LCD data direction is output
	_delay_ms(20);
	
	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0c);              //Command - Display on Cursor off
	LCD_Command(0x06);              //Command - shift cursor to right
	LCD_Command(0x01);              //Command - Clear display
	
	LCD_String("Welcome");
	_delay_ms(1000);
	LCD_String(".");
	_delay_ms(1000);
	LCD_String(".");
	_delay_ms(1000);
	LCD_String(".");
	_delay_ms(1000);
}


//this is the function use to write a string on the LCD screen
void Screen::LCD_String(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char (str[i]);
	}
}


//function to clear the display
void Screen::LCD_clear()
{
	LCD_Command (0x01);
	_delay_ms(2);
	LCD_Command (0x80);
}


/*demo function to display the Time. Here I used only the string "Time"
But in the alarm clock we can use the Time output comes from the RTC sub system. */
void Screen::Time()
{
	LCD_clear();
	LCD_String("~~~~ TIME ~~~~");
	_delay_ms(500);
}

/* Below functions are defined to explain that the user pressed a particular button.
But the code below contains only demo functions which can be modified to build the alarm menu
Will update them in my up coming commits.*/

//What to do when select button is pressed
void Screen::Select(){          
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

void Screen::Back(){            //what to do when user press the back button
  if (_state == 1 or _state ==2 or _state == 3 or _state == 4 or _state == 5) {           
    _state = 0;
    Time();
    _delay_ms(500);
  }
}


void Screen::Up(){              //what to do when the user press the up button
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
    if (_co == 0){                   //change a (Time is in this form - ab:cd)
      if (_a != 2)  {_a = _a +1; }
      else { _a = 0; }
      LCD_clear();
      show();
      LCD_Command(0XC0);
      LCD_String("Ok          Back");
      LCD_Command(0x02);
      _delay_ms(500);
      _co = 0;
    }

    if (_co == 1){                  //change b (Time is in this form - ab:cd)
      if (_a != 2){
        if (_b != 9) {_b = _b + 1; }
        else {_b = 0;}
        }
      else{
        if (_b != 4) {_b = _b + 1; }
        else {_b = 0;}
        }
      LCD_clear();
      show();
      LCD_Command(0XC0);
      LCD_String("Ok          Back");
      LCD_Command(0x80);
      _delay_ms(500);
      _co = 1;
      }


    if (_co == 3){                   //change c (Time is in this form - ab:cd)
      if (_c != 5)  {_c = _c +1; }
      else { _c = 0; }
      LCD_clear();
      show();
      LCD_Command(0XC0);
      LCD_String("Ok          Back");
      //lcd.setCursor(3,0);
      _delay_ms(500);
      _co = 3;
      }

    if (_co == 4){                   //change d (Time is in this form - ab:cd)
      if (_d != 9)  {_d = _d +1; }
      else { _d = 0; }
      LCD_clear();
      show();
      LCD_Command(0XC0);
      LCD_String("Ok          Back");
      //lcd.setCursor(4,0);
      _delay_ms(500);
      _co = 4;
      }
    }
}



//What to do when Down button is pressed

void Screen::Down(){         
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
    if (_co == 0){                   //change a (Time is in this form - ab:cd)
      if (_a != 0)  {_a = _a -1; }
      else { _a = 2; }
      LCD_clear();
      show();
      LCD_Command(0XC0);
      LCD_String("Ok          Back");
      LCD_Command(0x02);
      _delay_ms(500);
      _co = 0;
    }

    if (_co == 1){                  //change b (Time is in this form - ab:cd)
      if (_a != 2){
        if (_b != 0) {_b = _b - 1; }
        else {_b = 9;}
        }
      else{
        if (_b != 0) {_b = _b - 1; }
        else {_b = 4;}
        }
      LCD_clear();
      show();
      LCD_Command(0XC0);
      LCD_String("Ok          Back");
      LCD_Command(0x80);
      _delay_ms(500);
      _co = 1;
      }


    if (_co == 3){                   //change c (Time is in this form - ab:cd)
      if (_c != 0)  {_c = _c -1; }
      else { _c = 5; }
      LCD_clear();
      show();
      LCD_Command(0XC0);
      LCD_String("Ok          Back");
      //lcd.setCursor(3,0);
      _delay_ms(500);
      _co = 3;
      }

    if (_co == 4){                   //change d (Time is in this form - ab:cd)
      if (_d != 0)  {_d = _d -1; }
      else { _d = 9; }
      LCD_clear();
      show();
      LCD_Command(0XC0);
      LCD_String("Ok          Back");
      //lcd.setCursor(4,0);
      _delay_ms(500);
      _co = 4;
      }
    }
}


void Screen::Right(){              //right button can be used to move through a,b,c,d where Time = ab:cd
  if (_co == 0){
  _co = 1;
  LCD_Command(0x14);
  _delay_ms(500);
  }

  else if (_co == 1){
  _co = 3;
  LCD_Command(0x14);
  _delay_ms(500);
  }

  else if (_co == 3){
  _co = 4;
  LCD_Command(0x14);
  _delay_ms(500);
  }
}

//What to do when Left button is pressed
void Screen::Left(){             
  if (_co == 1){
  _co = 0;
  LCD_Command(0x10);
  _delay_ms(500);
  }

  else if (_co == 3){
  _co = 1;
  LCD_Command(0x10);
  _delay_ms(500);
  }

  else if (_co == 4){
  _co = 3;
  LCD_Command(0x10);
  _delay_ms(500);
  }
} 




void Screen::state_1(){
  _state = 1;
  LCD_clear();
  LCD_String("Set Alarm");
  _delay_ms(500);
}

void Screen::state_2(){
  _state = 2;
  LCD_clear();
  LCD_String("Set Time");
  _delay_ms(500);
}

void Screen::state_3(){
  _state = 3;
  LCD_clear();
  LCD_String("Existing Alarms");
  _delay_ms(500);
}

void Screen::state_4(){
  _state = 4;
  LCD_clear();
  LCD_String("Change Alarms");
  _delay_ms(500);
}

void Screen::state_5(){
  _state = 5;
  LCD_clear();
  LCD_String("Factory Reset");
  _delay_ms(500);
}

void Screen::state_6(){
  LCD_clear();
  show();
  LCD_Command(0XC0);
  LCD_String("Ok          Back");
  LCD_Command(0x02);
  LCD_Command(0x0E);
  _delay_ms(500);
}

void Screen::state_7(){
  LCD_clear();
  LCD_Command(0x02);
  _co = 0;
  char c_a = _a + 48;
  char c_b = _b + 48;
  char c_c = _c + 48;
  char c_d = _d + 48;
  LCD_Char(c_a); LCD_Char(c_b); LCD_String(":"); LCD_Char(c_c); LCD_Char(c_d);
  LCD_Command(0XC0);
  LCD_String("Yes           No");
  _delay_ms(500);
}

void Screen::state_8(){
  _a , _b , _c , _d = 0,0,0,0;
  state_6();
}

void Screen::show(){
	LCD_clear();
	char c_a = _a + 48;
	char c_b = _b + 48;
	char c_c = _c + 48;
	char c_d = _d + 48;
	LCD_Char(c_a); LCD_Char(c_b); LCD_String(":"); LCD_Char(c_c); LCD_Char(c_d);
}

