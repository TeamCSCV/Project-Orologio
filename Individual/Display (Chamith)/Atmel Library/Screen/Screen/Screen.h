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
	void Time();
	void Select();
	void Back();
	void Up();
	void Down();
	void Left();
	void Right();
	int _state;
	int _co;
	void state_1();
	void state_2();
	void state_3();
	void state_4();
	void state_5();
	void state_6();
	void state_7();
	void state_8();
	void show();
	char c_a ;
	char c_b ;
	char c_c ;
	char c_d ;
};

#endif
