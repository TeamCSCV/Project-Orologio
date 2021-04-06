/*
  Display.h - Library for Alarm display.
  Created by Chamith Dilshan 06-04-2021
*/


#ifndef Display_h
#define Display_h

#include "Arduino.h"


class Display
{
    public:
        Display(int select_button, int back_button, int down_button, int up_button, int state );
        void select();
        void back();
        void down();
        void up();
        void start();
        void time();

    private:
        int _select;
        int _back;
        int _down;
        int _up;
        int _state;
};

#endif;