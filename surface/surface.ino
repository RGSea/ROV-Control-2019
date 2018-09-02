// ROV Control 2019 - Surface
// Version 1, August

// library includes
#include "config.h"

// global variables
int motorSpeeds[8] = {10,50,30,40,50,60,70,80};


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
