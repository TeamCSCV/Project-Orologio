#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "Tone.h"

Tone alarmTone(2);

int main(void)
{_delay_ms(1000);
	
	
	int i=0;
	while(1){
		
		alarmTone.playMelody(i);
		i++;
		if (i>5){i=1;}
	}
	
}
