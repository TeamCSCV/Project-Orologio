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
#include "Screen.h"
#include "Key_Pad.h"

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

Screen sc;
Key_Pad kp;

// default constructor
Settings::Settings()
{
} //Settings

// default destructor
Settings::~Settings()
{
} //~Settings

int alarmArray[5]={-1,-1,-1,-1,-1};
int monthsDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
uint8_t year = 0;
uint8_t month = 0;
uint8_t day = 0;
uint8_t dayofweek = 0;
uint8_t hour = 0;
uint8_t minute = 0;
uint8_t second = 0;
char p;
char q;
char r;
char se;
int y, m, d, D, h, M, s;

int menu_i = 0;
char menu[4][16] = {"Set Alarm", "Set Time","Delete Alarms", "Factory Reset"};

int ith_alarm=0;

int powerOf(int base, int power){
	int result = 1;
	while(power!=0){
		result*=base;
		power--;
	}
	return result;
	
}

void LED(char P){
	PORTC|=1<<P;
	_delay_ms(500);
	PORTC&=~(1<<P);
	_delay_ms(500);
}

//--------------------------------------------------------------------------------------

void showTime()
{	
	sc.LCD_Command (0x80);
	ds1307_getdate(&year, &month, &day, &dayofweek, &hour, &minute, &second);
	sc.LCD_String("Time: ");
	sc.LCD_Char((char) (hour/10)+48);
	sc.LCD_Char((char) (hour%10)+48);
	sc.LCD_String(":");
	sc.LCD_Char((char) (minute/10)+48);
	sc.LCD_Char((char) (minute%10)+48);
	sc.LCD_String(":");
	sc.LCD_Char((char) (second/10)+48);
	sc.LCD_Char((char) (second%10)+48);
	sc.LCD_Command(0XC0);
	sc.LCD_String("Date: ");
	sc.LCD_String("20");
	sc.LCD_Char((char) (year/10)+48);
	sc.LCD_Char((char) (year%10)+48);
	sc.LCD_String("-");
	sc.LCD_Char((char) (month/10)+48);
	sc.LCD_Char((char) (month%10)+48);
	sc.LCD_String("-");
	sc.LCD_Char((char) (day/10)+48);
	sc.LCD_Char((char) (day%10)+48);
}

bool btnPress(uint8_t p){
	if (PIND == 1<< p){
		return true;
	}
	else{
		return false;
	}
}

//----------------------------------------------------------------------------------------------------------------------
void setClockTime(){
	sc.LCD_clear();
	sc.LCD_String("Set time here");
	sc.LCD_Command(0xc0);
	sc.LCD_String("hh : mm");
	//sc.LCD_Command(0XC0);
	//sc.LCD_String("YY : MM : DD");
	//sc.LCD_Command(0x80);
	
	while (1){
		sc.LCD_Command(0xc0);
		sc.blink();
		h = (int (kp.pressedKey())-48)*10;
		sc.LCD_Char((char) (h/10)+48);
		h += (int (kp.pressedKey()) -48);
		sc.LCD_Char((char) (h%10)+48);
		sc.stopBlink();
		_delay_ms(250);
		
		if(h<24){
			break;
		}
		sc.LCD_Command(0xc0); 
		sc.LCD_String("hh");
		}
	
	sc.LCD_String(" : ");
	while(1){
		sc.blink();
		M = (int (kp.pressedKey())-48)*10;
		sc.LCD_Char((char) (M/10)+48);
		M += (int (kp.pressedKey()) -48);
		sc.LCD_Char((char) (M%10)+48);
		_delay_ms(250);
		sc.stopBlink();
		
		if (M<60){
			break;
		}
		sc.LCD_Command(0xc0);  
		moveCursorRight(5);
		sc.LCD_String("mm");
		moveCursorLeft(2);}
		
	
	
	int s=0;
	
	_delay_ms(500);
	
	sc.LCD_clear();
	sc.LCD_String("Set date here");
	sc.LCD_Command(0xc0);
	sc.LCD_String("YY : MM : DD");
	sc.LCD_Command(0xc0);

	sc.blink();
	int y = (int (kp.pressedKey())-48)*10;
	sc.LCD_Char((char) (y/10)+48);
	y += (int (kp.pressedKey()) -48);
	sc.LCD_Char((char) (y%10)+48);
	sc.stopBlink();
	_delay_ms(250);
	
	sc.LCD_String(" : ");
	
	while(1){
		sc.blink();
		m = (int (kp.pressedKey())-48)*10;
		sc.LCD_Char((char) (m/10)+48);
		m += (int (kp.pressedKey()) -48);
		sc.LCD_Char((char) (m%10)+48);
		_delay_ms(250);
		sc.stopBlink();
		
		if (m<13){
			break;
		}
		sc.LCD_Command(0xc0);
		moveCursorRight(5);
		sc.LCD_String("MM");
	moveCursorLeft(2);}
	
	
	sc.LCD_String(" : ");
	
	while(1){
		sc.blink();
		d = (int (kp.pressedKey())-48)*10;
		sc.LCD_Char((char) (d/10)+48);
		d += (int (kp.pressedKey()) -48);
		sc.LCD_Char((char) (d%10)+48);
		_delay_ms(250);
		sc.stopBlink();
		
		if (d<monthsDays[m-1]){
			break;
		}
		sc.LCD_Command(0xc0);
		moveCursorRight(10);
		sc.LCD_String("DD");
	moveCursorLeft(2);}
	
	int D = getDay(y,m,d);
	ds1307_setdate(y,m, d, D, h, M, s);
		
}

//-------------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------- 

void set_alarm(){
	if (ith_alarm==5){
	sc.LCD_clear();
	sc.LCD_String("ALARM STORAGE");
	sc.LCD_Command(0xc0);
	sc.LCD_String("FULL !!!");
	_delay_ms(2000);
	return;
	}
	
	sc.LCD_clear();
	sc.LCD_String("hh : mm");
	sc.LCD_Command (0x80);
	sc.blink();
	char p = kp.pressedKey();
	sc.LCD_Char(p);
	char q = kp.pressedKey();
	sc.LCD_Char(q);
	sc.LCD_String(" : ");
	char r = kp.pressedKey();
	sc.LCD_Char(r);
	char se = kp.pressedKey();
	sc.LCD_Char(se);
	sc.stopBlink();
	_delay_ms(2000);
	
	if (((int) p-48)*1000 + ((int) q-48)*100  + ((int) r-48)*10 + ((int) se-48) > 2359){
		sc.LCD_clear();
		sc.LCD_String("ALARM NOT VALID!");
		_delay_ms(1000);
		set_alarm();
		return;
	}
	
	 
	alarmArray[ith_alarm] = ((int) p-48)*1000 + ((int) q-48)*100  + ((int) r-48)*10 + ((int) se-48);
    ith_alarm+=1;
	sc.LCD_clear();
	sc.LCD_String("AlARM SAVED :)");
	_delay_ms(1000);
	return;
}

//--------------------------------------------------------------------------------------

void deleteAlarm(){
	int ith =0;
	if (alarmArray[ith]==-1){
		sc.LCD_clear();
		sc.LCD_Char((char) ( ith+ 49));
		sc.LCD_String(". NONE");
	}
	else {
		sc.LCD_clear();
		sc.LCD_Char((char) ( ith+ 49));
		sc.LCD_String(". ");
		int _hour=alarmArray[ith]/100;
		int _minute=alarmArray[ith]%100;
		
		sc.LCD_Char((char) (_hour/10)+48);
		sc.LCD_Char((char) (_hour%10)+48);
		sc.LCD_String(":");
		sc.LCD_Char((char) (_minute/10)+48);
		sc.LCD_Char((char) (_minute%10)+48);
	}
	
	
	while(1){
		
		char btn = sc.Control_buttons();
		if (btn=='d'){
			switch(ith)
			{
				case 4: ith = 0; break;
				default: ith ++; break;
			}
		}
		
		else if (btn=='u'){
			switch (ith)
			{
				case 0: ith = 4; break;
				default: ith --; break;
			}
		}
		
		if (alarmArray[ith]==-1){
			sc.LCD_clear();
			sc.LCD_Char((char) ( ith+ 49));
			sc.LCD_String(". NONE");
		}
		else {
			sc.LCD_clear();
			sc.LCD_Char((char) ( ith+ 49));
			sc.LCD_String(". ");
			int _hour=alarmArray[ith]/100;
			int _minute=alarmArray[ith]%100;
			
			sc.LCD_Char((char) (_hour/10)+48);
			sc.LCD_Char((char) (_hour%10)+48);
			sc.LCD_String(":");
			sc.LCD_Char((char) (_minute/10)+48);
			sc.LCD_Char((char) (_minute%10)+48);
		}
	
	
	
	}
}

//-----------------------------------------------------------------------------------------------

void factoryReset(){
	sc.LCD_clear();
	
	sc.LCD_String("Are you sure?");
	sc.LCD_Command(0xc0);
	sc.LCD_String("Yes           No");
	while(1){
		if (sc.pressedSelect()){
			int alarmArray[5] ={-1,-1,-1,-1,-1};
			ds1307_setdate(00,01,01, 00,00,00,00);
			sc.LCD_String("Please Wait");
//This process is to be shown as a percentange			
			_delay_ms(1000);
			sc.LCD_String(".");
			_delay_ms(1000);
			sc.LCD_String(".");
			_delay_ms(1000);
			sc.LCD_String(".");
			_delay_ms(1000);
			sc.LCD_clear();
			_delay_ms(10);
			sc.LCD_String("Please Wait");
			_delay_ms(1000);
			sc.LCD_String(".");
			_delay_ms(1000);
			sc.LCD_String(".");
			_delay_ms(1000);
			sc.LCD_String(".");
			_delay_ms(1000);
			sc.LCD_clear();
			sc.LCD_String("DONE!!!");
			_delay_ms(1000);
			sc.LCD_clear();
			break;
		}
		else if (sc.pressedBack()){
			return;
		}
	}
	
	
		
}

void moveCursorRight(int i){
	for (int l=0; l<i;l++){
		sc.LCD_Command(0x14);
	}
}

void moveCursorLeft(int j){
	for (int k =0; k<j; k++){
		sc.LCD_Command(0x10);
	}
}


void mainMenu()
{
	sc.LCD_clear();
	sc.LCD_String(menu[menu_i]);
	
	while(1){
		
		char btn = sc.Control_buttons();
		if (btn=='d'){
			switch(menu_i)
			{
				case 3: menu_i = 0; break;
				default: menu_i ++; break;
			}
		}
		else if (btn=='u'){
			switch (menu_i)
			{
				case 0: menu_i = 3; break;
				default: menu_i --; break;
			}
		}
		
		else if (btn=='b'){
			mainLoop();
		break;}
		
		else if (btn=='s'){
			switch (menu_i)
			{case 0:
				set_alarm();
				break;
				
				case 1:
				setClockTime();
				break;
				
				case 2:
				deleteAlarm();
				break;
				case 3:
				factoryReset();
				break;
				
			}
		}
		

		sc.LCD_clear();
		sc.LCD_String(menu[menu_i]);
		_delay_ms(500);
		
		
		
	}
}

void mainLoop(){
	showTime();
	if (sc.pressedSelect()){
		sc.LCD_clear();
		mainMenu();
}
}