#ifndef Tone_h
#define Tone_h

#include "Arduino.h"

class Tone
{
    public:
        Tone(int pin);
        void melody1();
        void melody2();
    private:
        int _pin;
};

#endif