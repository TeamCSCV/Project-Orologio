/*
 * Key_Pad.h
 *
 * Created: 2021-04-22 10:21:00 PM
 *  Author: Senuri Ranatunga
 */ 


#ifndef Key_Pad_h_
#define Key_Pad_h_
#define F_CPU 16000000UL
#include <avr/io.h>

/*
Rows          Columns
R1 >> PD0     C1 >> PD4
R2 >> PD1     C2 >> PD5
R3 >> PD2     C3 >> PD6
R4 >> PD3

LEDs
LED1 (2^3) >> PC0
LED2 (2^2) >> PC1
LED3 (2^1) >> PC2
LED4 (2^0) >> PC3
 */
class Key_Pad
{
	public:
	//KEYPAD IS ATTACHED ON PORTD

	#define KEY_PORT PORTD
	#define KEY_DDR   DDRD
	#define KEY_PIN   PIND

	//LEDs ARE ATTACHED ON PORTC

	#define LED_PORT PORTC
	#define LED_DDR   DDRC
	#define LED_PIN   PINC
	
	char keyInput();
	void Led();
	
	};


#endif /* Key_Pad_h_ */