/* 
* Settings.h
*
* Created: 5/17/2021 11:30:51 AM
* Author: vinuj
*/


#ifndef __SETTINGS_H__
#define __SETTINGS_H__
#include <avr/io.h>

class Settings
{
//variables
public:
char a;
char b;
char c;
char d;
protected:
private:


//functions
public:
	Settings();
	~Settings();
protected:
private:
	Settings( const Settings &c );
	Settings& operator=( const Settings &c );

}; //Settings
extern bool btnPress(uint8_t p);
extern int powerOf(int base, int power);
extern void showTime();
extern void updateAlarmArray(int removeAlarm);
extern void setClockTime();
extern int getDay(int y, int m, int d);
extern void set_alarm();
extern void deleteAlarm();
extern void factoryReset();
extern void mainMenu();
extern void mainLoop();
extern void moveCursorRight(int i);
extern void moveCursorLeft(int j);
#endif //__SETTINGS_H__
