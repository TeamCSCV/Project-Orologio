#ifndef Tone_h
#define Tone_h

#include "Arduino.h"

class Tone
{
    public:
        Tone(int pin);
        void melody1();
        void melody2();
        void melody3();
        void melody4();
    private:
        int _pin;
};

#endif