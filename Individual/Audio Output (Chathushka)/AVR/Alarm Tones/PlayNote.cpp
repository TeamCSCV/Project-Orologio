/*
 * GccLibrary1.cpp
 *
 * Created: 4/24/2021 7:06:29 PM
 * Author : Chathushka
 */ 

#include <avr/io.h>
#define SPEAKER_PORT PORTB
#define SPEAKER_DDR DDRB
#define SPEAKER_PIN 3

void delay_ms(uint16_t count) {
	while(count) {
		_delay_ms(1);
		count--;
	}
}

void delay_us(uint16_t count) {
	while(count) {
		_delay_us(1);
		count--;
	}
}

void PLAYNOTE(float duration, float frequency)
{
	long int i,cycles;
	float half_period;
	float wavelength;
	
	wavelength=(1/frequency)*1000;
	cycles=2*duration/wavelength;
	half_period = wavelength/2;

	SPEAKER_DDR |= (1 << SPEAKER_PIN);
	
	for (i=0;i<cycles;i++)
	{
		delay_ms(half_period);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		delay_ms(half_period);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
	
}

