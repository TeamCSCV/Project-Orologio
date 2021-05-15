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

#define LCD_Dir DDRB            //defines some variables that the code using
#define LCD_Port PORTB
#define RS PB0
#define EN PB1               

int _state = 0;          //_state represents a numerical index given to the screen massage


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


/*demo function to display the time. Here I used only the string "Time"
But in the alarm clock we can use the time output comes from the RTC sub system. */
void Screen::Time()
{
	LCD_clear();
	LCD_String("~~~~ Time ~~~~");
	_delay_ms(500);
}

/* Below functions are defined to explain that the user pressed a particular button.
But the code below contains only demo functions which can be modified to build the alarm menu
Will update them in my up coming commits.*/

//What to do when select button is pressed
void Screen::Select()
{
	LCD_clear();
	LCD_String("Pressed Select");
	_delay_ms(500);
}

//What to do when Back button is pressed
void Screen::Back()
{
	LCD_clear();
	LCD_String("Pressed Back");
	_delay_ms(500);
}


//What to do when Up button is pressed
void Screen::Up()
{
	LCD_clear();
	LCD_String("Pressed Up");
	_delay_ms(500);
}

//What to do when Down button is pressed
void Screen::Down()
{
	LCD_clear();
	LCD_String("Pressed Down");
	_delay_ms(500);
}

//What to do when Left button is pressed
void Screen::Left()
{
	LCD_clear();
	LCD_String("Pressed Left");
	_delay_ms(500);
}

//what to do when Right button is pressed
void Screen::Right()
{
	LCD_clear();
	LCD_String("Pressed Right");
	_delay_ms(500);
}