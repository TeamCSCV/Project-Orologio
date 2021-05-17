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
//extern void getAlarmTime();
extern void ringAlarm();
extern void setAlarm(int alarm_time);
extern void checkAlarm();
extern void updateAlarmArray(int removeAlarm);
extern void setClockTime(int clockTime[6]);
extern int getDay(int y, int m, int d);

#endif //__SETTINGS_H__
