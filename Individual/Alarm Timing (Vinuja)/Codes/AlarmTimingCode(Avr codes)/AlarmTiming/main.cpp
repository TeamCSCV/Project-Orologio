#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include "ds1307.h"
#include "Settings.h"
#include "util/delay.h"

int mode = 0;
int data = 0;
int AlarmState = 3;
int ClockState = 0;
int temp = 0;
int alarmTime = 0;
int clockTime[6];

void LED(char P){
	PORTB|=1<<P;
	_delay_ms(500);
	PORTB&=~(1<<P);
	_delay_ms(500);
}
void getAlarmTime(){
	if (btnPress(PIND1)){
		if(data==9){
			data=0;
			_delay_ms(500);
		}else{
			LED(PORTB1);
			data++;
			_delay_ms(500);	
		}
		
	}
	if (btnPress(PIND3)){
		LED(PORTB2);
		alarmTime += data*powerOf(10,AlarmState);
		AlarmState--;
		data=0;
		_delay_ms(500);
	}
	if (AlarmState == -1){
		setAlarm(alarmTime);
		AlarmState = 3;
		alarmTime = 0;
		mode = 0;
		_delay_ms(500);
	}
}
void getClockTime(){
	if (btnPress(PIND1)){
		if(data==9){
			data=0;
			_delay_ms(500);
			}else{
			LED(PORTB1);
			data++;
			_delay_ms(500);
		}
		
	}
	if (btnPress(PIND3)){
		LED(PORTB2);
		if (temp == 0){
			data*=10;
			temp = 1;
		}
		else{
			clockTime[ClockState] = data;
			ClockState++;
			data=0;
			temp = 0;
		}
		_delay_ms(500);
	}
	if (ClockState == 6){
		setClockTime(clockTime);
		ClockState = 0;
		mode = 0;
		_delay_ms(500);
	}
}
int main(void)
{
	ds1307_init();
	while (1)
	{
		checkAlarm();
		if (btnPress(PIND7)){
			if(mode==2){
				mode=0;
				_delay_ms(500);
			}else{
				mode++;
				LED(PORTB3);
				_delay_ms(500);
			}
		}
		if (mode == 1){
			getAlarmTime();
		}
		if (mode == 2){
			getClockTime();
		}
	}
}
