/*
 * Screen.h
 *
 * Created: 5/8/2021
 *  Author: Chamith Ranathunga
 *  Header file for the Screen library
 */ 

#ifndef Screen_h
#define Screen_h

#include <avr/io.h>

class Screen                //objects I need under the class Screen
{
	public:
	#define LCD_Dir DDRB
	#define LCD_Port PORTB
	#define RS PB0
	#define EN PB1
	void LCD_Command(unsigned char cmnd);
	void LCD_Char(unsigned char data);
	void LCD_Init(void);
	void LCD_String(char *str);
	void LCD_clear();
	void Time();
	void Select();
	void Back();
	void Up();
	void Down();
	void Left();
	void Right();
	int _state;
};

#endif
