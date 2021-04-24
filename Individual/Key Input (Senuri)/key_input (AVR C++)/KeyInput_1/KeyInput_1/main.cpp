/*
 * KeyInput_1.cpp
 *
 * Created: 2021-04-22 10:01:41 PM
 * Author : Senuri Ranatunga
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL

//KEYPAD IS ATTACHED ON PORTB

#define KEY_PORT PORTB
#define KEY_DDR   DDRB
#define KEY_PIN   PINB

//LEDs ARE ATTACHED ON PORTC

#define LED_PORT PORTC
#define LED_DDR   DDRC
#define LED_PIN   PINC
/*
Rows          Columns
R1 >> PB0     C1 >> PB4
R2 >> PB1     C2 >> PB5
R3 >> PB2     C3 >> PB6
R4 >> PB3

LEDs
LED1 (2^3) >> PC0
LED2 (2^2) >> PC1
LED3 (2^1) >> PC2
LED4 (2^0) >> PC3
 */
unsigned char keys[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

//Scanning the keypad repeatedly to check whether a key is pressed
char keyInput(){
	
	KEY_DDR |= 0b00001111 ; //set the row pins to OUTPUT
	KEY_PORT |= 0b00001111; //set all row pins to HIGH
	for (int r=0; r<=3; r++){
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


void Led(){
	LED_DDR |= 0b00001111; // set the first 4 pins to Output
	char key = keyInput(); // obtain the returned value of the function
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
			binary[i]=key_no%2;
			key_no=key_no/2;
		    for (int i=0; i<=3; i++){ // turn on or off the LEDs according to the binary value of the key
			    if (binary[i]==1){ 
					LED_PORT = LED_PORT | (1<<i); // 1 --> LED on
			    }
			    else{
				    LED_PORT = LED_PORT & (~(1<<i)); // 0 --> LED off
			    }
			    }
		    }		
   }
}
 int main(void)
 {
	 while(1)
	 {
		 Led(); // calling the Led() function repeatedly
	 }
	 return 0;
 }
