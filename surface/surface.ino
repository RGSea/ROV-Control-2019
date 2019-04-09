// ROV Control 2019 - Surface
// Version e = pi = 3

/*
To do:
- Implement control station controls
- Extend serial comms buffer for electromagnets
- Extend serial comms to receive temperature data
*/


// file includes
#include "config.h"                                     // include config file
#include <XBOXUSB.h>                                    // include XBOXUSB library
#ifdef dobogusinclude                                   // catch for XBOXUSB special SPI requirement        
  #include <spi4teensy3.h>                              // include special SPI
#endif                                                  // end of special SPI catch
#include <SPI.h>                                        // include SPI library

// class object creation
USB Usb;                                                // create USB object to allow polling of controller
XBOXUSB Xbox(&Usb);                                     // create XBOX controller object

// global variables
uint16_t motorSpeeds[8] = {0, 0, 0, 0, 0, 0, 0, 0};     // motor speeds, array index corresponds to motor index           
int32_t Lx, Ly, Rx, Ry, LT, RT;                         // controller axis input values
bool LB, RB;                                            // controller button states
uint8_t loopNum = 0;                                    // main loop number
bool magnetStates[6] = {0, 0, 0, 0, 0, 0};              // electromagnet states (controls A0-A5 in order)


// initialisation
void setup() {

  // initialise other files
  initComms();                                          // initialise comms code
	initControlInput();                                   // initialise control input

  // run motor calibration
  #ifdef CALIBRATE_MOTORS                               // check for motor calibration debug flag
    calibrateMotors();                                  // run motor calibration
  #endif                                                // end of motor calibration debug flag

  resetMotorSpeeds();                                   // set motor speeds to zero
  calcMotorSpeeds();                                    // calculate motor speeds for initialisation (all zero)
  sendData(motorSpeeds, magnetStates);                  // send initial motor speed data (all zero)
  delay(2000);                                          // pause 2s to allow system to come online

}


// main loop
void loop() {

  // control code
	fetchControlInput();                                   // fetch control input from XBOX controller
	calcMotorSpeeds();                                     // calculate motor speeds

  // send comms data every 50th loop
  if((loopNum % 50) == 0){                               // check for loop number 50
    loopNum = 0;                                         // reset loop number every 50th loop
    sendData(motorSpeeds, magnetStates);                 // send comms data every 50th loop
  }
  loopNum += 1;                                          // increment loop number

}



