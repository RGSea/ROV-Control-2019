// ROV Control 2019 - Onboard
// version e = pi = 3


/*
To do:
- Add electromagnet data receive to comms
- Test electromagnet outputs
- Implement temperature sensor
- Add temperature sensor data send to comms
*/


// file includes
#include "config.h"                                   // include configuration file
#include <Servo.h>                                    // include ESC control library
#include <OneWire.h>                                  // include onewire library for temp sensor
#include <DallasTemperature.h>                        // include temp sensor library

// servo object creation
Servo FL_H;                                           // servo object for front left horizontal ESC
Servo FR_H;                                           // servo object for front right horizontal ESC
Servo BL_H;                                           // servo object for back left horizontal ESC
Servo BR_H;                                           // servo object for back right horizontal ESC
Servo FL_V;                                           // servo object for front left vertical ESC
Servo FR_V;                                           // servo object for front right vertical ESC
Servo BL_V;                                           // servo object for back left vertical ESC
Servo BR_V;                                           // servo object for back right vertical ESC

// temperature sensor object creation
OneWire oneWire(ONE_WIRE_BUS);                        // create onewire bus connection
DallasTemperature sensors(&oneWire);                  // create temperature sensor object

// global variables
String dataIn = "";                                   // data input buffer
boolean dataPacketRecieved = false;                   // data packet recieved statues
uint16_t motorSpeeds[8] = {0, 0, 0, 0, 0, 0, 0, 0};   // motor speeds
bool magnetStates[6] = {0,0,0,0,0,0};                 // electromagnet states


// initialisation
void setup() {

  // set ESC pins to outputs                          // *** do this all using DDR next time, much faster and fewer lines of code ***
  pinMode(PIN_FL_H, OUTPUT);                          // set front left horizontal ESC pin to output
  pinMode(PIN_FR_H, OUTPUT);                          // set front right horizontal ESC pin to output
  pinMode(PIN_BL_H, OUTPUT);                          // set back left horizontal ESC pin to output
  pinMode(PIN_BR_H, OUTPUT);                          // set back right horizontal ESC pin to output
  pinMode(PIN_FL_V, OUTPUT);                          // set front left vertical ESC pin to output
  pinMode(PIN_FR_V, OUTPUT);                          // set front right vertical ESC pin to output
  pinMode(PIN_BL_V, OUTPUT);                          // set back left vertical ESC pin to output
  pinMode(PIN_BR_V, OUTPUT);                          // set back right vertical ESC pin to output

  // set electromagnet pins to outputs
  pinMode(PIN_MAG_1, OUTPUT);                         // set electromagnet 1 pin to output
  pinMode(PIN_MAG_2, OUTPUT);                         // set electromagnet 2 pin to output
  pinMode(PIN_MAG_3, OUTPUT);                         // set electromagnet 3 pin to output
  pinMode(PIN_MAG_4, OUTPUT);                         // set electromagnet 4 pin to output
  pinMode(PIN_MAG_5, OUTPUT);                         // set electromagnet 5 pin to output
  pinMode(PIN_MAG_6, OUTPUT);                         // set electromagnet 6 pin to output

  // initialise other files
	initComms();                                        // initialise serial comms
	initESCs();                                         // initialise ESCs
	
}


// main loop
void loop() {

	writeToESCs();                                       // write motor speeds to ESCs
  writeToElectromagnets();                             // write to electromagnet outputs

}
