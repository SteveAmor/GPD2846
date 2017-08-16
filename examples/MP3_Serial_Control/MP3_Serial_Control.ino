/*
  MP3_Serial_Control.ino - Example to control GPD2846 MP3 player.
  Created by Stephen Amor, August 16, 2017.
  Released into the public domain.
  Connect S1, S2 and S3 pads direct to Arduino pins (D2, D3, D4 in this example).
  Also need a common ground between the Arduino and MP3 player so connect GND between the two.
  You can also power the MP3 player via the Arduino 5v (BAT+ on MP3 player).
  Run the serial monitor and use single character commands to change volume, skip tracks and play / pause.
*/

#include <GPD2846.h>

GPD2846 mp3(2,3,4); // Arduino pins D2 = S1, D3 = S2, D4 = S3 on MP3 player

void setup() {
  Serial.begin(115200);
}

void loop() {
  checkForSerialCommand();
}

void checkForSerialCommand() {
  char serialCommand=' ';
  if(Serial.available()>0) {
    serialCommand=Serial.read();
    Serial.flush();
  }
  switch(serialCommand) {
    case 'f': // skip forward
      mp3.next();  
      break;
    case 'd': // volume down
      mp3.volumeDown();
      break;
    case 'p': // pause on or off
      mp3.pause();  // could use mp3.play();
      break;
    case 'b': // skip back
      mp3.previous();
      break;
    case 'u': // volume up
      mp3.volumeUp();
      break;
    default:
      break;    
  }
}
