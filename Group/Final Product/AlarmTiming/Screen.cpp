/*
 * Screen.cpp
 *
 * Created: 5/8/2021
 *  Author: Chamith Ranathunga
 *  .cpp file for the library screen
 */ 
#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 1000000UL

#include <avr/io.h>              //#include the header files I want
#include <util/delay.h>
#include "Screen.h"           




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
	/*LCD_String(".");
	_delay_ms(1000);
	LCD_String(".");
	_delay_ms(1000);
	LCD_String(".");
	_delay_ms(1000);*/
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


char Screen::Control_buttons(){
	DDRB = 0xCF;
	DDRD &= 0b11110011;
	while (1)
	{
		if (PINB & 0b00010000){
			_delay_ms(1500);
			return 's' ;
			break;
		}
		else if (PINB & 0b00100000){
			_delay_ms(1500);
			return 'b';
			break;
		}
		else if (PIND & 0b000000100){
			_delay_ms(1500);
			return 'u';
			break;
		}
		else if (PIND & 0b000001000){
			_delay_ms(1500);
			return 'd';
			break;
		}
		
	}
	
}

char Screen::pressedButton(){
	DDRB = 0xCF;
	DDRD &= 0b11110011;
		if (PINB & 0b00010000){
			_delay_ms(1500);
			return 's' ;
		}
		else if (PINB & 0b00100000){
			_delay_ms(1500);
			return 'b';
		}
		else if (PIND & 0b000000100){
			_delay_ms(1500);
			return 'u';
		}
		else if (PIND & 0b000001000){
			_delay_ms(1500);
			return 'd';
		}
		else{
			return '0';
		}
	
}



void Screen::blink(){
	LCD_Command(0x0F);
}

void Screen::stopBlink(){
	LCD_Command(0x0c);
}

bool  Screen::pressedSelect(){
	if (PINB & 0b00010000) {
		_delay_ms(1000);
		return true;
	}
	else {
		return false;
	}
}

bool  Screen::pressedBack(){
	if (PINB & 0b00100000){
		_delay_ms(2000);
		return true;
	}
	else{
		return false;
	}
}