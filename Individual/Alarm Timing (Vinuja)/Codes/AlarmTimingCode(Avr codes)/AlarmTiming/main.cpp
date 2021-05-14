#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include "ds1307.h"

int mode = 0;
int select=0;
int AlarmOneMin=0;
int AlarmOneHour=0;
int AlarmTwoMin=0;
int AlarmTwoHour=0;
int AlarmThreeMin=0;
int AlarmThreeHour=0;
int year=21;
int month=0;
int date=0;

void LED(char P){
	PORTB|=1<<P;
	_delay_ms(1000);
	PORTB&=~(1<<P);
	_delay_ms(1000);
}
void setDay(){
}
void setAlarmOne(){
	
}
void setAlarmTwo(){
	
}
void setAlarmThree(){

}

void setYear(){
	//LED(PORTB0);
	if((PIND & (1<<PIND5))){
		LED(PORTB3);
		year++;
	}
}

void setMonth(){
	//LED(PORTB0);
	if((PIND & (1<<PIND5))){
		LED(PORTB4);
		if(month==12){
			month=1;
		}else{
			month++;
		}		
	}
}
void setDate(){
	if((PIND & (1<<PIND5))){
		if(date==31){
			date=1;
		}else{
			date++;
		}
			
	}
	
}


void setAlarmOneHour(){
	if((PIND & (1<<PIND5))){
		LED(PORTB5);
		if(AlarmOneHour==23){
			AlarmOneHour=0;
		}else{
			AlarmOneHour++;
			
		}
	}
}

void setAlarmOneMin(){
	if((PIND & (1<<PIND5))){
		LED(PORTB5);
		if(AlarmOneMin==59){
			AlarmOneMin=0;
		}else{
			AlarmOneMin++;
			
		}
	}
}

void setAlarmTwoHour(){
	if((PIND & (1<<PIND5))){
		LED(PORTB5);
		if(AlarmTwoHour==23){
			AlarmTwoHour=0;
			}else{
			AlarmTwoHour++;
			
		}
	}
}

void setAlarmTwoMin(){
	if((PIND & (1<<PIND5))){
		LED(PORTB5);
		if(AlarmTwoMin==59){
			AlarmTwoMin=0;
			}else{
			AlarmTwoMin++;
			
		}
	}
}

void setAlarmThreeHour(){
	if((PIND & (1<<PIND5))){
		LED(PORTB5);
		if(AlarmThreeHour==23){
			AlarmThreeHour=0;
			}else{
			AlarmThreeHour++;
			
		}
	}
}

void setAlarmThreeMin(){
	if((PIND & (1<<PIND5))){
		LED(PORTB5);
		if(AlarmThreeMin==59){
			AlarmThreeMin=0;
			}else{
			AlarmThreeMin++;
			
		}
	}
}
int main(void) {
	DDRB=0b01111111;
	DDRD=0b00000000;
	ds1307_init();
	
	uint8_t year = 0;
	uint8_t month = 0;
	uint8_t day = 0;
	uint8_t hour = 0;
	uint8_t minute = 0;
	uint8_t second = 0;
	//check set date
	//ds1307_setdate(21, 12, 31, 23, 59, 35);
	
	while(1) {
		//get date
		ds1307_getdate(&year, &month, &day, &hour, &minute, &second);
		//blinking alarmLED
		if(AlarmOneHour==2){
			LED(PORTB0);
			
		}else{
			PORTB&=~(1<<PORTB0);
		}
		
		//changing the mode
		if(PIND & (1<<PIND7)){
			if(mode==4){
				mode=0;
			}else{
				mode++;
				LED(PORTB1);
			}
		}
		
		//setting mode to functions
		if(mode==0){
			//LED(PORTB1);
		}
		//Changing the year,month,date
		else if(mode==1){
			//LED(PORTB2);
			if((PIND & (1<<PIND3))){
				//LED(PORTB3);
				if(select==3){
					select=0;
				}else{
					select++;
					LED(PORTB2);
				}
			}
			
			if(select==0){
				//LED(PORTB4);
			}
			else if(select==1){
				//LED(PORTB2);
				setYear();
			}
			else if(select==2){
				//LED(PORTB3);
				setMonth();
				
			}else{
				//LED(PORTB5);
				setDate();
			}
		
		}
		if(mode==2){
			//LED(PORTB3);
			if((PIND & (1<<PIND3))){
				//LED(PORTB3);
				if(select==2){
					select=0;
				}else{
					select++;
					LED(PORTB2);
				}
			}
			if(select==0){
				//LED(PORTB4);
			}
			else if(select==1){
				//LED(PORTB4);
				setAlarmOneHour();
			}
			else if(select==2){
				//LED(PORTB3);
				setAlarmOneMin();
				
				}
		}
		else if(mode==3){
			//LED(PORTB5);
			if((PIND & (1<<PIND3))){
				//LED(PORTB3);
				if(select==2){
					select=0;
					}else{
					select++;
					LED(PORTB2);
				}
			}
			if(select==0){
				//LED(PORTB4);
			}
			else if(select==1){
				//LED(PORTB4);
				setAlarmTwoHour();
			}
			else if(select==2){
				//LED(PORTB3);
				setAlarmTwoMin();
				
			}
		}else{
			//LED(PORTB5);
			if((PIND & (1<<PIND3))){
				//LED(PORTB3);
				if(select==2){
					select=0;
					}else{
					select++;
					LED(PORTB2);
				}
			}
			if(select==0){
				//LED(PORTB4);
			}
			else if(select==1){
				//LED(PORTB4);
				setAlarmThreeHour();
			}
			else if(select==2){
				//LED(PORTB3);
				setAlarmThreeMin();
				
			}
		}
		
			
		
	}
}

