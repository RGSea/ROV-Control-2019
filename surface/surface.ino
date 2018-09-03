// ROV Control 2019 - Surface
// Version 1, August

// library includes
#include "config.h"

#include <XBOXUSB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
USB Usb;
XBOXUSB Xbox(&Usb);

// global variables
int motorSpeeds[8] = {10,50,30,40,50,60,70,80};
int Lx, Ly, Rx, Ry, LT, RT;


// initialisation
void setup() {

	initComms();
	initControlInput();

}


// main loop
void loop() {

	fetchControlInput();
	//calcMotorSpeeds();
  for(int i = 0; i < 8; i++) {
    motorSpeeds[i] = 10 * i;
  }
  motorSpeeds[1] = 80;
	sendData(motorSpeeds);

}
