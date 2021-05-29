/*
 * Key_Pad.cpp
 *
 * Created: 2021-04-20 8:39:10 PM
 * Author : Senuri Ranatunga
 */ 

#include "Key_Pad.h"
unsigned char keys[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

//Scanning the keypad repeatedly to check whether a key is pressed
char Key_Pad :: keyInput(){
	
	KEY_PORT |= 0b00001111; //set all row pins to HIGH
	for (int r=0; r<=3; r++){
		KEY_DDR &= ~0b01111111; //clearing previous bits
		KEY_DDR |= 0b00000001 << r ; //set the current pin to output
		KEY_PORT &= ~(0b00000001 << r); // set the current row pin to LOW
		for (int c=0; c<=2; c++){
			KEY_PORT |= (0b00010000 << c);
			if (!(KEY_PIN & (0b00010000 << c))){ // check each column in the respective row for a pressed key
				char pressed = keys[r][c]; // obtain the pressed key
				if ((pressed!='*') & (pressed!='#')){
					return pressed;
				}
				return 'X';
			}
		}
	}
	return 'X';
}


void Key_Pad :: Led(){
	LED_DDR |= 0b00001111; // set the pins to Output
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

