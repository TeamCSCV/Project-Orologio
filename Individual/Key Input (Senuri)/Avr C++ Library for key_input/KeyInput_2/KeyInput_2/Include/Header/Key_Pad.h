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

char keyInput();
void Led();

//char keys[3][4]={{'#','9','6','3'},{'0','8','5','2'},{'*','7','4','1'}};

#endif /* KEY_PAD_H_ */