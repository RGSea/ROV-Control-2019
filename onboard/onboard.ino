// ROV Control 2019 - Onboard
// Version 1, August

// library includes
#include "config.h"
#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>

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

// temperature sensor
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


// initialisation
void setup() {

	initComms();
	initESCs();
  //sensors.begin();
	
}


// main loop
void loop() {

	//recvData(); // now interrupt driven
	writeToESCs();
  
  /*float temp = getTempValue();
  #ifdef PRINT_TEMP_VAL
    Serial.print("temperature: \t");
    Serial.println(temp);
  #endif*/
  

}
