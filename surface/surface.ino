// ROV Control 2019 - Surface
// Version 1, August-September

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
int motorSpeeds[8] = {0,0,0,0,0,0,0,0};
int Lx, Ly, Rx, Ry, LT, RT;
bool LB, RB;


// initialisation
void setup() {

	initComms();
	initControlInput();

}


// main loop
void loop() {

	fetchControlInput();
	calcMotorSpeeds(); 
	sendData(motorSpeeds);

}
