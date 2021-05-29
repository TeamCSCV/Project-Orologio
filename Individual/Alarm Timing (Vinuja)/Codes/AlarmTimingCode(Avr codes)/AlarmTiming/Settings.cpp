/* 
* Settings.cpp
*
* Created: 5/17/2021 11:30:51 AM
* Author: vinuj
*/


#include "Settings.h"
#include "util/delay.h"
#include <avr/io.h>
#include "ds1307.h"
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

// default constructor
Settings::Settings()
{
} //Settings

// default destructor
Settings::~Settings()
{
} //~Settings

int numberOfAlarms = 0;
int alarmArray[10];
int monthsDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
uint8_t year = 0;
uint8_t month = 0;
uint8_t day = 0;
uint8_t dayofweek = 0;
uint8_t hour = 0;
uint8_t minute = 0;
uint8_t second = 0;
int powerOf(int base, int power){
	int result = 1;
	while(power!=0){
		result*=base;
		power--;
	}
	return result;
	
}
bool btnPress(uint8_t p){
	if (PIND == 1<< p){
		return true;
	}
	else{
		return false;
	}
}
void ringAlarm(){
	DDRB |= 1<<PORTB0;
	PORTB |= 1<<PORTB0;
	_delay_ms(60000);
	PORTB = 0;
}
void setAlarm(int alarm_time){
	alarmArray[numberOfAlarms] = alarm_time;
	numberOfAlarms++;
}
void updateAlarmArray(int removeAlarm){
	for (int i=0;i<numberOfAlarms;i++){
		if (i<removeAlarm){
			alarmArray[i] = alarmArray[i];
		}
		else{
			alarmArray[i] = alarmArray[i+1];
		}
	}
}
void checkAlarm(){
	if (numberOfAlarms != 0){
		ds1307_getdate(&year, &month, &day, &dayofweek, &hour, &minute, &second);
		for (int i = 0; i <= numberOfAlarms;i++){
			if (alarmArray[i]/100 == hour && alarmArray[i]%100 == minute){
				ringAlarm();
				updateAlarmArray(i);
				numberOfAlarms--;
			}
		}
		
	}
}
void setClockTime(int clockTime[6]){
	int y = clockTime[0];
	int m = clockTime[1];
	int d = clockTime[2];
	int D = getDay(y,m,d);
	int h = clockTime[3];
	int M = clockTime[4];
	int s = clockTime[5];
	ds1307_setdate(y, m, d, D, h, M, s);
}
int getDay(int y, int m, int d){
	int days = 0;
	for (int i = 1;i<=y;i++){
		if (i%4 == 0){
			days+= 366;
		}
		else{
			days+= 365;
		}
		
	}
	for (int j = 0;j<m-1;j++){
		if ((y%4==0) & (j == 1)){
			days+=monthsDays[j];
			days+=1;
		}
		else{
			days +=monthsDays[j];
		}
	}
	return (days+d+5)%7;
}