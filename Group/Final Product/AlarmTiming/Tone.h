/*
  Tone.cpp - Library to Store the data of five alarm tones.
  Created by Chathushka Ranasinghe, May 8, 2021. 
*/
#ifndef Tone_h
#define Tone_h

class Tone
{
    public:
        Tone(int pin_1);
        char melody1();
        char melody2();
        char melody3();
        char melody4();
        char melody5();
        void playNote(float frequency, float duration);
        char playMelody(int number);
    private:
        int SPEAKER_PIN;
};

#endif
