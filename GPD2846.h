/*
  GPD2846.h - Library for MP3 player board.
  Created by Stephen Amor, August 16, 2017.
  Released into the public domain.
*/

#ifndef GPD2846_h
#define GPD2846_h

#include "Arduino.h"

class GPD2846
{
  public:
    GPD2846(int pinS1, int pinS2, int pinS3);
    void volumeUp();
    void volumeDown();
    void next();
    void previous();
    void play();
    void pause();
  private:
    int _pinS1;
    int _pinS2;
    int _pinS3;
    void _highZ();
};

#endif
