/*
  Tone.cpp - Library to Store the data of five alarm tones.
  Created by Chathushka Ranasinghe, April 7, 2020. 
*/

#ifndef Tone_h
#define Tone_h

#include "Arduino.h"

class Tone
{
    public:
        Tone(int pinBuzzer,int pinButton);
        void melody1();
        void melody2();
        void melody3();
        void melody4();
        void melody5();
        void play(int Number);
    private:
        int _pinBuzzer;
        int _pinButton;
};

#endif