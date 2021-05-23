/*
  Tone.cpp - Library to Store the data of five alarm tones.
  Created by Chathushka Ranasinghe, May 8, 2021. 
*/
#ifndef Tone_h
#define Tone_h

class Tone
{
    public:
        Tone(int pin_1,int pin_2);
        void melody1();
        void melody2();
        void melody3();
        void melody4();
        void melody5();
        void playNote(float frequency, float duration);
        void playMelody(int number);
    private:
        int SPEAKER_PIN;
        int BUTTON_PIN;
};

#endif
