// ROV Control 2019 - Surface
// Version e = pi = 3

// library includes
#include "config.h"
#include "menu.h"
#include <XBOXUSB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

// class object creation
USB Usb;
XBOXUSB Xbox(&Usb);

// global variables
int motorSpeeds[8] = {0,0,0,0,0,0,0,0};
int Lx, Ly, Rx, Ry, LT, RT;
bool LB, RB;
int loopNum = 0;

// initialisation
void setup() {

  // initialise serial comms
  initComms();

  // initialise additional code
	initControlInput();

  // run motor calibration if specified by config
  #ifdef CALIBRATE_MOTORS
    calibrateMotors();
  #endif

  resetMotorSpeeds();
  calcMotorSpeeds();
  sendData(motorSpeeds);
  delay(5000);

}


// main loop
void loop() {

  // control code
	fetchControlInput();
	calcMotorSpeeds();

  // send motorspeeds data
  if((loopNum % 50) == 0){       // sends data every 50th loop (measured at approx 10-20. Hz (depends on intensity of calc.))
    loopNum = 0;
    sendData(motorSpeeds);
  }
  loopNum += 1;

}



