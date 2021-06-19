/*
 * Key_Pad.cpp
 *
 * Created: 2021-04-20 8:39:10 PM
 * Author : Senuri Ranatunga
 */
#include <util/delay.h> 

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 1000000UL

#include "Key_Pad.h"
#include "Screen.h" 
#include "Settings.h"

Screen sc2;

char keys[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

//Scanning the keypad repeatedly to check whether a key is pressed
char Key_Pad :: keyInput(){
	while (1){
		if (sc2.pressedBack()){
			sc2.stopBlink();
			sc2.LCD_clear();
			mainMenu();

		}
		KEYROW_PORT |= 0b00001111; //set all row pins to HIGH
		for (int r=0; r<=3; r++){
			KEYROW_DDR &= ~0b00001111; //clearing previous bits
			KEYCOL_DDR &= ~0b00000111; //clearing previous bits
			KEYROW_DDR |= 0b00000001 << r ; //set the current pin to output
			KEYROW_PORT &= ~(0b00000001 << r); // set the current row pin to LOW
			for (int c=0; c<=2; c++){
				KEYCOL_PORT |= (0b00000001 << c);
				if (!(KEYCOL_PIN & (0b00000001 << c))){ // check each column in the respective row for a pressed key
					char pressed = keys[r][c]; // obtain the pressed key
					if ((pressed!='*') & (pressed!='#')){
						return pressed;
					}
					return 'X';
				}
			}
		}
	return 'X';}
}

char Key_Pad :: pressedKey(){
	while (1){
	char key = keyInput();
	if (key != 'X'){
		_delay_ms(2000);
		return key; // if a number is pressed return the pressed key
	 }
	}
}





