#ifndef key_input_h
#define key_input_h

#include "Arduino.h"

class key_input
{
  public:
    key_input(int pin);
    int keyInput();
    void led(); 
  private:
    int _pin ;
};

#endif
