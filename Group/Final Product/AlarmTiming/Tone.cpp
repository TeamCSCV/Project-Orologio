/*
  Tone.cpp - Library to Store the data of five alarm tones.
  Created by Chathushka Ranasinghe, May 8, 2021.
  These are the melodies have been included.
  1 - A Normal Digial Alarm  Tone
  2 - Astronomia
  3 - Pirates of the Carribean Theme
  4 - Game of Thrones Theme
  5 - Sherlock Theme
*/

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define SPEAKER_PORT PORTB
#define SPEAKER_DDR DDRB

#include "Tone.h"
#include "Notes.h"

int changing;

Tone::Tone(int pin_1,int pin_2)
{
	SPEAKER_PIN=pin_1;
	BUTTON_PIN =pin_2;
}

//Function to play a single note

void Tone:: playNote(float frequency, float duration)
{
	duration*=0.5;
	long int cycles;
	float half_period;
	float wavelength;
	
	SPEAKER_DDR |= (1 << SPEAKER_PIN);
	if (frequency==0){
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
		_delay_us(duration);
		float pauseBetweenNotes= duration*2;
			_delay_ms (pauseBetweenNotes);
	}
	
	
	else{
		wavelength=(1/frequency)*1000;
		cycles=2*duration/wavelength;
		half_period = wavelength/2;

		
		
		for (int i=0;i<cycles;i++)
		{
			_delay_us(half_period*1000);
			SPEAKER_PORT |= (1 << SPEAKER_PIN);
			_delay_us(half_period*1000);
			SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
		}
	}
}

//Notes and their durations.

void Tone::melody1()
{
	int melody[] = {
		NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,0
	};

	int noteDurations[] = {
		4,4,4,4,1
	};
	
	int length = sizeof(noteDurations)/sizeof(noteDurations[0]);

	changing=0;
	while (changing==0)
	{
		
		for (int currentNote=0; currentNote<length;currentNote++)
		{
			int wantChange  = PINB & (1<<BUTTON_PIN);
			if( wantChange) {changing=1;break;}

			float noteDuration = 200 / noteDurations[currentNote];
			playNote(melody[currentNote],noteDuration);
			float pauseBetweenNotes= noteDuration*2;
			_delay_ms (pauseBetweenNotes);
			SPEAKER_PORT=0;
		}

	}

	_delay_ms(400);
}


void Tone:: melody2()
{
	
	int melody[] = {
		
		NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
		NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
		NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5,
		NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
		NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
		NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
		NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
		NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
		NOTE_G4, 0, NOTE_G4, NOTE_D5,
		NOTE_C5, 0, NOTE_AS4, 0,
		NOTE_A4, 0, NOTE_A4, NOTE_A4,
		NOTE_C5, 0, NOTE_AS4, NOTE_A4,
		NOTE_G4,0, NOTE_G4, NOTE_AS5,
		NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
		NOTE_G4,0, NOTE_G4, NOTE_AS5,
		NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
		NOTE_G4, 0, NOTE_G4, NOTE_D5,
		NOTE_C5, 0, NOTE_AS4, 0,
		NOTE_A4, 0, NOTE_A4, NOTE_A4,
		NOTE_C5, 0, NOTE_AS4, NOTE_A4,
		NOTE_G4,0, NOTE_G4, NOTE_AS5,
		NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
		NOTE_G4,0, NOTE_G4, NOTE_AS5,
		NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5
	};

	int noteDurations[] = {

		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
	};
	
	int length = sizeof(noteDurations)/sizeof(noteDurations[0]);
	
	changing=0;
	while (changing==0)
	{
		
		for (int currentNote=0; currentNote<length;currentNote++)
		{
			int wantChange  = PINB & (1<<BUTTON_PIN);
			if( wantChange) {changing=1;_delay_ms(100);break;}

			float noteDuration = 375 / noteDurations[currentNote];
			playNote(melody[currentNote],noteDuration);
			float pauseBetweenNotes= noteDuration*1.30;
			_delay_ms (pauseBetweenNotes);
			SPEAKER_PORT=0;
		}
		_delay_ms(400);
		
	}

}

void Tone:: melody3()
{
	int melody[] = {
		
		NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
		NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
		NOTE_A4, NOTE_G4, NOTE_A4,
		NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
		NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
		NOTE_A4, NOTE_G4, NOTE_A4,
		NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
		NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
		NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
		NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
		NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
		NOTE_D5, NOTE_E5, NOTE_A4, 0,
		NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
		NOTE_C5, NOTE_A4, NOTE_B4,
	};

	int noteDurations[] = {
		
		8, 8, 4, 8, 8,
		8, 8, 4, 8, 8,
		8, 8, 4, 8, 8,
		8, 8, 2,
		8, 8, 4, 8, 8,
		8, 8, 4, 8, 8,
		8, 8, 4, 8, 8,
		8, 8, 2,
		8, 8, 4, 8, 8,
		8, 8, 4, 8, 8,
		8, 8, 4, 8, 8,
		8, 8, 8, 4, 8,
		8, 8, 4, 8, 8,
		4, 8, 4, 8,
		8, 8, 4, 8, 8,
		8, 8, 2
	};
	
	int length = sizeof(noteDurations)/sizeof(noteDurations[0]);
	

	changing=0;
	while (changing==0)
	{
		for (int currentNote=0; currentNote<length;currentNote++)
		{
			int wantChange  = PINB & (1<<BUTTON_PIN);
			if( wantChange) {changing=1;_delay_ms(100);break;}

			float noteDuration = 375 / noteDurations[currentNote];
			playNote(melody[currentNote],noteDuration);
			float pauseBetweenNotes= noteDuration*1.30;
			_delay_ms (pauseBetweenNotes);
			SPEAKER_PORT=0;
		}
		_delay_ms(400);
	}
}

void Tone:: melody4()
{
	int melody[] = {
		NOTE_G4,
		NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_G4,
		NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_D4,
		NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
		NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
		NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
		NOTE_G3,NOTE_AS3,NOTE_F4,NOTE_AS3,
		NOTE_AS3,NOTE_D4,NOTE_F4,NOTE_AS3,
		NOTE_DS4,NOTE_D4,NOTE_GS3,NOTE_F3,
		NOTE_GS3,NOTE_G3,NOTE_C4,NOTE_F3,
		NOTE_GS3,NOTE_G3,NOTE_GS3,NOTE_F3,
		NOTE_GS3,NOTE_G3,NOTE_C4,NOTE_F3,
		NOTE_G4,NOTE_C4,NOTE_DS4,
		NOTE_F4,NOTE_G4,NOTE_C4,NOTE_DS4,
		NOTE_F4,NOTE_D4,NOTE_G3,NOTE_AS3,
		NOTE_C4,NOTE_D4,NOTE_G3,NOTE_AS3,
		NOTE_C4,NOTE_D4,NOTE_G3,NOTE_AS3,
		NOTE_C4,NOTE_D4,NOTE_G3,NOTE_AS3,
		NOTE_F4,NOTE_AS3,NOTE_AS3,NOTE_D4,
		NOTE_F4,NOTE_AS3,NOTE_DS4,NOTE_D4,
		NOTE_GS3,NOTE_F3,NOTE_GS3,NOTE_G3,
		NOTE_C4,NOTE_F3,NOTE_GS3,NOTE_G3,
		NOTE_GS3,NOTE_F3,NOTE_GS3,NOTE_G3,
		NOTE_C4,NOTE_F3
	};

	int noteDurations[] = {
		12,12,24,24,
		12,12,24,24,
		12,12,24,24,
		12,12,24,24,
		12,12,24,24,
		12,12,24,24,
		12,12,24,24,
		12,12,24,24,
		4,4,24,24,
		6,6,24,24,
		12,12,24,24,
		12,12,24,24,
		12,12,24,24,
		12,12,12,4,
		4,24,24,6,
		6,24,24,12,
		12,24,24,12,
		12,24,24,12,
		12,24,24,12,
		12
	};
	
	int length = sizeof(noteDurations)/sizeof(noteDurations[0]);
	
	changing=0;
	while (changing==0)
	{
		
		for (int currentNote=0; currentNote<length;currentNote++)
		{
			int wantChange  = PINB & (1<<BUTTON_PIN);
			if( wantChange) {changing=1;_delay_ms(100);break;}


			float noteDuration = 1375 / noteDurations[currentNote];
			playNote(melody[currentNote],noteDuration);
			float pauseBetweenNotes= noteDuration*1.30;
			_delay_ms (pauseBetweenNotes);
			SPEAKER_PORT=0;
		}
		_delay_ms(1000);
	}
}


void Tone:: melody5()
{
	int melody[] = {
		NOTE_C4,NOTE_G4,
		NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_GS4,
		NOTE_G4,NOTE_F4,NOTE_C5,NOTE_C5,
		NOTE_F4,NOTE_C5,NOTE_C5,NOTE_B4,
		NOTE_C5,NOTE_D5,NOTE_C5,NOTE_DS5,
		NOTE_DS5,NOTE_G5,NOTE_C5,NOTE_C5,
		NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_C5,
		NOTE_F5,NOTE_C5,0,0,
		0,NOTE_C5,NOTE_D5,NOTE_DS5,
		NOTE_DS5,NOTE_F5,NOTE_D5,NOTE_D5,
		NOTE_DS5,NOTE_C5,NOTE_C5,NOTE_D5,
		NOTE_B4,NOTE_GS4,NOTE_G4,NOTE_C5,0,
		NOTE_G5,NOTE_C5,NOTE_C5,
		NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_C5,
		NOTE_F5,NOTE_C5,0,0,
		0,NOTE_C5,NOTE_D5,NOTE_DS5,
		NOTE_DS5,NOTE_F5,NOTE_D5,NOTE_D5,
		NOTE_DS5,NOTE_C5,NOTE_C5,NOTE_D5,
		NOTE_B4,NOTE_GS4,NOTE_G4,NOTE_C5
		
	};
	
	

	int noteDurations[] = {
		12,6,
		12,24,24,6,
		12,12,4,3,
		12,6,12,24,
		24,6,12,3,
		3,12,6,12,
		12,12,12,12,
		12,12,6,6,
		12,24,24,12,
		24,24,12,24,
		24,12,24,24,
		12,24,24,3,3,
		12,6,12,
		12,12,12,12,
		12,12,6,6,
		12,24,24,12,
		24,24,12,24,
		24,12,24,24,
		12,24,24,3
	};
	
	int length = sizeof(noteDurations)/sizeof(noteDurations[0]);

	changing=0;
	while (changing==0)
	{
			for (int currentNote=0; currentNote<length;currentNote++)
			{
				int wantChange  = PINB & (1<<BUTTON_PIN);
				if( wantChange) {changing=1;_delay_ms(100);break;}

				
				float noteDuration = 375*3 / noteDurations[currentNote];
				playNote(melody[currentNote],noteDuration);
				float pauseBetweenNotes= noteDuration*1.30;
				_delay_ms (pauseBetweenNotes);
				SPEAKER_PORT=0;
			}
			
		_delay_ms(400);
	}
}

void Tone:: playMelody(int number){

	switch (number) {
		case 1:
		melody1();
		break;
		case 2:
		melody2();
		break;
		case 3:
		melody3();
		break;
		case 4:
		melody4();
		break;
		case 5:
		melody5();
		break;
	}

}