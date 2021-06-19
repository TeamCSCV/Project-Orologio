/*
 * Key_Pad.h
 *
 * Created: 2021-04-22 10:21:00 PM
 *  Author: Senuri Ranatunga
 */ 


#ifndef Key_Pad_h_
#define Key_Pad_h_
#define __DELAY_BACKWARD_COMPATIBLE__
#define  F_CPU 1000000UL

#include <avr/io.h>

/*
Rows          Columns
R1 >> PC0     C1 >> PB0
R2 >> PC1     C2 >> PB1
R3 >> PC2     C3 >> PB2
R4 >> PC3
 */

class Key_Pad
{
	public:
	//ROWS OF THE KEYPAD ARE ATTACHED ON PORTC

	#define KEYROW_PORT PORTC
	#define KEYROW_DDR   DDRC
	#define KEYROW_PIN   PINC
	
	//COLUMNS OF THE KEYPAD ARE ATTACHED ON PORTB

	#define KEYCOL_PORT PORTB
	#define KEYCOL_DDR   DDRB
	#define KEYCOL_PIN   PINB
	
	char keyInput();
	char pressedKey();
};

#endif /* Key_Pad_h_ */