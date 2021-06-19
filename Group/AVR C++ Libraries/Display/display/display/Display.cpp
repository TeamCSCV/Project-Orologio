/*
 * Display.cpp
 *
 * Created: 6/8/2021
 *  Author: Chamith Ranathunga
 *  .cpp file for the library Display of the final product
 */ 

#include <avr/io.h>              //#include the header files I want
#include <util/delay.h>
#include "Display.h"           

#define LCD_Dir DDRD           //defines some variables that the code using
#define LCD_Port PORTD
#define RS PD0
#define EN PD1      
     

          
int _a=0 , _b=0 , _c=0 , _d=0;   //assume that the Time is in ab:cd format
int menu_i = 0;

char menu[4][16] = {"Set Alarm", "Set Time", "Change Alarms", "Factory Reset"};

//this command is use to send a command to the LCD as an unsigned char
void Display::LCD_Command(unsigned char cmnd)      
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

void Display::LCD_Char(unsigned char data)
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


//function to initialize the LCD display
void Display::LCD_Init(void)
{
	LCD_Dir = 0xFF;			//LCD data direction is output
	_delay_ms(20);
	
	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0c);              //Command - Display on Cursor off
	LCD_Command(0x06);              //Command - shift cursor to right
	LCD_Command(0x01);              //Command - Clear display
	
	/*LCD_String("Welcome");
	_delay_ms(1000);
	LCD_String(".");
	_delay_ms(1000);
	LCD_String(".");
	_delay_ms(1000);
	LCD_String(".");
	_delay_ms(1000);*/
}


//this is the function use to write a string on the LCD Display
void Display::LCD_String(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char (str[i]);
	}
}


//function to clear the display
void Display::LCD_clear()
{
	LCD_Command (0x01);
	_delay_ms(2);
	LCD_Command (0x80);
}


/*demo function to display the Time. Here I used only the string "Time"
But in the alarm clock we can use the Time output comes from the RTC sub system. */
void Display::Time()
{
	LCD_clear();
	LCD_String("~~~~ TIME ~~~~");
	_delay_ms(500);
}

void Display::Execute_buttons()
{
	 char x;
	 x = Control_buttons();
	 if (x=='u'){ 
		 switch(menu_i)
		 {
			 case 3: menu_i = 0; break;
			 default: menu_i ++; break;
		 }
	 }
	 else if (x=='d'){
		 switch (menu_i)
		 {
			 case 0: menu_i = 3; break;
			 default: menu_i --; break; 
		 }
	 }
		 
	 LCD_clear();
	 LCD_String(menu[menu_i]);
	 _delay_ms(500);
}
char Display::Control_buttons(){
	DDRB = 0xCF;
	DDRD &= 0b11110011;
	while (1)
	{
		if (PINB == 1<<4){
			return 'u' ;
			break;      
		}
		else if (PINB == 1<<5){
			return 'd';
			break;  
		}
		else if (PIND & 0b00000100){
			return 'u';
			break;
		}
		else if (PIND & 0b00001000){
			return 'd';
			break;
		}
		
	}
}