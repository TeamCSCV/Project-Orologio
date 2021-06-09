/*
 * Display.h
 *
 * Created: 6/8/2021
 *  Author: Chamith Ranathunga
 *  Header file for the Display library of final product 
 */ 

#ifndef Display_h
#define Display_h

#include <avr/io.h>

class Display                //objects I need under the class Display
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
	void level_1();
	void level_2();
	void level_3();
	void level_4();
	void level_5();
	void level_6();
	void level_7();
	void level_8();
	void show();
	char Control_buttons();
	void Execute_buttons();
	char c_a ;
	char c_b ;
	char c_c ;
	char c_d ;
	int menu_i;
};

#endif
