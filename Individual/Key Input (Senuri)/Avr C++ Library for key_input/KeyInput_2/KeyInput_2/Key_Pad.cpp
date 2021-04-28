/*
 * Key_Pad.cpp
 *
 * Created: 2021-04-20 8:39:10 PM
 * Author : Senuri Ranatunga
 */ 
//#include <avr/io.h>
#include "Key_Pad.h"


/* Replace with your library code */
//Scanning the keypad repeatedly to check whether a key is pressed
char keyInput(){
	while (1)
	{
		KEY_PORT |= 0x0F ; // set the row pins HIGH and column pins LOW (0000 1111)
		for (int c=0; c<=2; c++){ // check each column
			KEY_DDR = 0x00;
			KEY_DDR |= (0x40 >> c); // shift the bit 1 to the right by c amount (0100 0000 >> c)
			for (int r=0; r<=3; r++){
				if (!(KEY_PIN & (0x08 >> r))){ // check each row in the respective column for a pressed key
					// shift the bit 1 to the right by r amount (0000 1000 >> r)
					char pressed = keys[c][r];
					if ((pressed!='*') & (pressed!='#')){
						return pressed;
					}
					return 'X';
				}
			}
		}
		return 'X';
	}
}

void Led(){
	LED_DDR = 0x0F; // set the pins to Output
	char key = keyInput(); // obtain the pressed key
	if (key == 'X'){ // when a key is not pressed or when '*' or '#' is pressed turn off the LEDs
		LED_PORT = LED_PORT & (~(1<<0));
		LED_PORT = LED_PORT & (~(1<<1));
		LED_PORT = LED_PORT & (~(1<<2));
		LED_PORT = LED_PORT & (~(1<<3));
	}
	else{  // when a key is pressed
		int key_no = int(key) - int ('0'); // convert the key value from char to int
		int binary[4]={0,0,0,0};
		for (int i=3; i>=0 ;i--){ // obtain the binary number of the key
			binary[i]=key_no % 2;
			key_no=key_no / 2;
			for (int i=0; i<=3; i++){ // turn on or off the LEDs according to the binary value of the key
				if (binary[i]==1){
					LED_PORT = LED_PORT | (1<<i); // 1 >> LED on
				}
				else{
					LED_PORT = LED_PORT & (~(1<<i)); // 0 >> LED off
				}
			}
		}
	}
}

