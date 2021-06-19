
#define F_CPU 1000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include "ds1307.h"
#include "Settings.h"
#include "util/delay.h"
#include "Screen.h"
#include "Key_Pad.h"
#include "Tone.h"


Screen scrn;
Key_Pad key;
Tone alarmTone(3,4);


int main(void)
{
	ds1307_init();
	scrn.LCD_Init();
	while (1)
	{
		mainLoop();
			
	}
		
	
}







