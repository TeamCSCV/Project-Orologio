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
	#define LCD_Dir DDRD
	#define LCD_Port PORTD
	#define RS PD0
	#define EN PD1
	void LCD_Command(unsigned char cmnd);
	void LCD_Char(unsigned char data);
	void LCD_Init(void);
	void LCD_String(char *str);
	void LCD_clear();
	char Control_buttons();
	char pressedButton();

	
	void blink();
	void stopBlink();
	bool pressedSelect();
	bool pressedBack();
};

#endif
