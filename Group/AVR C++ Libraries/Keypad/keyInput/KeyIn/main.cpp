/*
 * KeyIn.cpp
 *
 * Created: 2021-05-29 11:45:16 AM
 * Author : Senuri Ranatunga
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "Key_Pad.h"

Key_Pad keyin;
 
 int main(void){
  char key = keyin.pressedKey();
 
 }
 

