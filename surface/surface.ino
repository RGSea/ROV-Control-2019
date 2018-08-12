// ROV Control 2019 - Surface
// Version 1, August

// library includes
#include "config.h"

// global variables
int motorSpeeds[8] = {0, 0, 0, 0, 0, 0, 0, 0};


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
