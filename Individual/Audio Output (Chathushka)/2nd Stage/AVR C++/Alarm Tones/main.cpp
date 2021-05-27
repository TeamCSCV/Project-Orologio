#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "Tone.h"

//Creating an object from the Class 'Tone'

Tone alarmTone(2,1); // Enter pin numbers of the Buzzer and the Push Button respectively (PORT B)

int main(void)
{_delay_ms(1000);
	
	
	int i=0;
	while(1){
		
		alarmTone.playMelody(i);
		i++;
		if (i>5){i=1;}
	}
	
}
