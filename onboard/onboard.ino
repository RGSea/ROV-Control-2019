// ROV Control 2019 - Onboard
// Version 1, August

// library includes
#include "config.h"
#include <Servo.h>

// servo object creation
Servo FL_H;
Servo FR_H;
Servo BL_H;
Servo BR_H;
Servo FL_V;
Servo FR_V;
Servo BL_V;
Servo BR_V;

// global variables
String dataIn = "";
boolean dataPacketRecieved = false;
int motorSpeeds[8] = {0, 0, 0, 0, 0, 0, 0, 0};


// initialisation
void setup() {

	initComms();
	initESCs();
  
	
}


// main loop
void loop() {

	recvData();
	//writeToESCs();
  FL_H.write(motorSpeeds[1]);
	


	// working pins:

}
