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