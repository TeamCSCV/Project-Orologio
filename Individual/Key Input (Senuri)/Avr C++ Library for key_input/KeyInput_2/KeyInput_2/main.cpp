/*
 * KeyInput_2.cpp
 *
 * Created: 2021-04-22 10:05:20 PM
 * Author : Senuri Ranatunga
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "Key_Pad.h"
	
 int main(void)
 {
	 while (1)
	 {
		 Led(); // calling the Led() function repeatedly
	 }
	 return 0;
 }
