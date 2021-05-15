/*
 * Key_Pad.h
 *
 * Created: 2021-04-22 10:21:00 PM
 *  Author: Senuri Ranatunga
 */ 


#ifndef KEY_PAD_H_
#define KEY_PAD_H_
#include <avr/io.h>
#define F_CPU 8000000UL

//using namespace std;
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
char keyInput();
void Led();



#endif /* KEY_PAD_H_ */