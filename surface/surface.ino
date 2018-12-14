// ROV Control 2019 - Surface
// Version 3.14159263535897932

// library includes
#include "config.h"
#include "menu.h"
#include "Encoder.h"
#include <XBOXUSB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

// class object creation
USB Usb;
XBOXUSB Xbox(&Usb);
Encoder encoder(ENCODER_PIN_1, ENCODER_PIN_2);

// global variables
int motorSpeeds[8] = {0,0,0,0,0,0,0,0};
int Lx, Ly, Rx, Ry, LT, RT;
bool LB, RB;
long oldEncoderPos  = -2;
long encoderRotation = 0;
bool switchState = false;

#define INDEX_YAW_GAIN        0
#define INDEX_PITCH_GAIN      1
#define INDEX_ROLL_GAIN       2
#define INDEX_FWDBWD_GAIN     3
#define INDEX_LEFTRIGHT_GAIN  4
#define INDEX_ALTITUDE_GAIN   5
double gainVals[8] = {1.2, 1, 1, 1, 1, 1, 1, 1};


// initialisation
void setup() {

  // initialise serial comms
  initComms();

  // set pin registers
  pinMode(SWITCH_PIN, INPUT_PULLUP);

  // initialise additional code
	initControlInput();

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
	sendData(motorSpeeds);




  // encoder code
  /*
  switchState = digitalRead(SWITCH_PIN);
  //Serial.println(switchState);

	long newEncoderPos = encoder.read();


  if (newEncoderPos != oldEncoderPos) {
    //Serial.println(newEncoderPos - oldEncoderPos);
    updateGain(&gainVals[INDEX_YAW_GAIN], (int)(newEncoderPos - oldEncoderPos));
    oldEncoderPos = newEncoderPos;
  }

  //Serial.println(gainVals[INDEX_YAW_GAIN]);*/
  


}



