/*
 * main.cpp
 *
 * Created: 5/8/2021
 * Author : Chamith Ranathunga
 * Main code for LCD display screen
 */ 

#define F_CPU 1000000UL

#include <avr/io.h> 
#include <util/delay.h>
#include "Screen.h"           //include the header files I want

#define ButtonDir DDRD
Screen scrn;                 

int main(void)
{
	ButtonDir = 0;
    scrn.LCD_Init();         //initialize the LCD Display
	scrn.Time();            //at the beginning the time will be shown
	
	//in the following loop the program will always be looking for an input from buttons
	while (1)      
    {
		if (PIND == 1<<0){
			scrn.Select();      //call Select function when user press the select button
		}
		else if (PIND == 1<<1){
			scrn.Left();       //call Left function when user press the Left button
		}
		else if (PIND == 1<<2){
			scrn.Down();       //call Down function when user press the Down button
		}
		else if (PIND == 1<<3){
			scrn.Up();         //call Up function when user press the Up button
		}
		else if (PIND == 1<<4){
			scrn.Right();     //call Right function when user press the Right button
		}
		else if (PIND == 1<<5){
			scrn.Back();     //call Back function when user press the Back button
		}		
	}
}