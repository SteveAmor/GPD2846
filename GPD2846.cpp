/*
  GPD2846.cpp - Library for MP3 player board.
  Created by Stephen Amor, August 16, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "GPD2846.h"


GPD2846::GPD2846(int pinS1, int pinS2, int pinS3)
{
  pinMode(pinS1, INPUT);
  _pinS1 = pinS1;
  pinMode(pinS2, INPUT);
  _pinS2 = pinS2;
  pinMode(pinS3, INPUT);
  _pinS3 = pinS3;
}

void GPD2846::volumeUp()
{
  pinMode(_pinS3, OUTPUT); // pin goes low
  delay(1000);
  _highZ();
  delay(100);
}

void GPD2846::volumeDown()
{
  pinMode(_pinS1, OUTPUT); // pin goes low
  delay(1000);
  _highZ();
  delay(100);
}

void GPD2846::next()
{
  pinMode(_pinS3, OUTPUT); // pin goes low
  delay(100);
  _highZ();
  delay(100);
}

void GPD2846::previous()
{
  pinMode(_pinS1, OUTPUT); // pin goes low
  delay(100);
  _highZ();
  delay(100);
}

void GPD2846::play()
{
  pinMode(_pinS2, OUTPUT); // pin goes low
  delay(100);
  _highZ();
  delay(100);
}

void GPD2846::pause()
{
  pinMode(_pinS2, OUTPUT); // pin goes low
  delay(100);
  _highZ();
  delay(100);
}

void GPD2846::_highZ()
{
  pinMode(_pinS1, INPUT); // pin goes to tristate
  pinMode(_pinS2, INPUT); // pin goes to tristate
  pinMode(_pinS3, INPUT); // pin goes to tristate
}
