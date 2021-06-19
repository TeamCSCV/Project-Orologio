/*
 * main.cpp
 *
 * Created: 6/8/2021
 * Author : Chamith Ranathunga
 * Main code for LCD display of the final product
 */ 



#include <avr/io.h> 
#include <util/delay.h>
#include "Display.h"          //include the header files I want

Display disp;                 

int main(void)
{
			
    disp.LCD_Init();         //initialize the LCD Display
	disp.Time();            //at the beginning the time will be shown
	while (1)
	{
		disp.Execute_buttons();
	}
}