// control algorithm (trims in development)


// control algorithm to calculate motor speeds
void calcMotorSpeeds() {

	// local variables for calculation
	int altitude = RT - LT;                                                                                        // calculate altitude component, difference between triggers
	int pitch = Ry;                                                                                                // calculate pitch component                                                                          
	int roll = Rx;                                                                                                 // calculate roll component
  int inPut = sqrt((Lx*Lx)+(Ly*Ly));                                                                             // calculate magnitude of translation input

	// calculate vertical motor speeds
	motorSpeeds[INDEX_FL_V] = altitude - pitch + roll;
	motorSpeeds[INDEX_FR_V] = altitude - pitch - roll;
	motorSpeeds[INDEX_BL_V] = altitude + pitch + roll;
	motorSpeeds[INDEX_BR_V] = altitude + pitch - roll;

	// calculate horizontal motor speeds
  motorSpeeds[INDEX_FR_H] = ( inPut * (Lx-Ly) ) / abs((Lx + Ly)) + (YAWRATE * RB) - (YAWRATE * LB) + 1;
  motorSpeeds[INDEX_FL_H] = (( inPut * (-Lx-Ly)) / abs((Lx + Ly)) - (YAWRATE * RB) + (YAWRATE * LB)) + 1;
  motorSpeeds[INDEX_BR_H] = ( inPut * (Lx+Ly) ) / abs((Lx + Ly)) - (YAWRATE * RB) + (YAWRATE * LB) + 1;
  motorSpeeds[INDEX_BL_H] = ( inPut * (Ly-Lx) ) / abs((Lx + Ly)) + (YAWRATE * RB) - (YAWRATE * LB) +1;

  // reverse motors if necessary
  if(REVERSE_FL_H) {motorSpeeds[INDEX_FL_H] = -1 * motorSpeeds[INDEX_FL_H];}
  if(REVERSE_FR_H) {motorSpeeds[INDEX_FR_H] = -1 * motorSpeeds[INDEX_FR_H];}
  if(REVERSE_BL_H) {motorSpeeds[INDEX_BL_H] = -1 * motorSpeeds[INDEX_BL_H];}
  if(REVERSE_BR_H) {motorSpeeds[INDEX_BR_H] = -1 * motorSpeeds[INDEX_BR_H];}
  if(REVERSE_FL_V) {motorSpeeds[INDEX_FL_V] = -1 * motorSpeeds[INDEX_FL_V];}
  if(REVERSE_FR_V) {motorSpeeds[INDEX_FR_V] = -1 * motorSpeeds[INDEX_FR_V];}
  if(REVERSE_BL_V) {motorSpeeds[INDEX_BL_V] = -1 * motorSpeeds[INDEX_BL_V];}
  if(REVERSE_BR_V) {motorSpeeds[INDEX_BR_V] = -1 * motorSpeeds[INDEX_BR_V];}

  // get values from control station inputs, scale values to range 0-1
  double masterPowerFactor = SPEED_LIMIT * double(fetchPotValue(INDEX_MASTER_POWER)) / 1023;        // get master power factor from dial, add additional software limit
  // /int altitudeTrim = ALTITUDE_TRIM * (1 - double(fetchPotValue(INDEX_ALTITUDE_TRIM)) / 1023);       // (1- used since scale is backwards)
  //int pitchTrim = PITCH_TRIM * double(fetchPotValue(INDEX_PITCH_TRIM)) / 1023;
  //int rollTrim = ROLL_TRIM * double(fetchPotValue(INDEX_ROLL_TRIM)) / 1023;
  
  // apply master power factor
  for(uint8_t i = 0; i < 8; i++) {
    motorSpeeds[i] = int(motorSpeeds[i] * masterPowerFactor);
  }
 
  // check motor speeds are valid
  for(uint8_t i = 0; i < 8; i++) {                        // loop through motor speeds
    checkSpeedRange(&motorSpeeds[i]);                     // check speed is valid
  }

	// print motor speeds if debug flag raised
	#ifdef DEBUG_VERTICAL_MOTOR_SPEEDS
    Serial.print("\n\n\n\n-----------------------\n");
		Serial.print("\t");
		Serial.print(motorSpeeds[INDEX_FL_V]);
		Serial.print("\t\t");
		Serial.print(motorSpeeds[INDEX_FR_V]);
		Serial.print("\n\n\n\n");
		Serial.print("\t");
		Serial.print(motorSpeeds[INDEX_BL_V]);
		Serial.print("\t\t");
		Serial.print(motorSpeeds[INDEX_BR_V]);
		Serial.print("\n");
	#endif

  #ifdef DEBUG_HORIZONTAL_MOTOR_SPEEDS
    Serial.print("\t");
    Serial.print(motorSpeeds[INDEX_FL_H]);
    Serial.print("\t");
    Serial.print(motorSpeeds[INDEX_FR_H]);
    Serial.print("\t\t");
    Serial.print(motorSpeeds[INDEX_BL_H]);
    Serial.print("\t");
    Serial.println(motorSpeeds[INDEX_BR_H]);
  #endif

  #ifdef DEBUG_TRIM_VALUES
    Serial.print(masterPowerFactor);
    Serial.print("\t");
    Serial.print(altitudeTrim);
    Serial.print("\t");
    Serial.print(pitchTrim);
    Serial.print("\t");
    Serial.print(rollTrim);
    Serial.println();
  #endif

}


// fetch value of potentiometer from control station
uint16_t fetchPotValue(uint8_t pin) {                     //returns value in range 0-100%

  uint16_t value = 0;                                     // value of reading
  value = analogRead(pin);                                // read value from pin
  return value;                                           // return value
  
}


// reset motor speeds to zero
void resetMotorSpeeds() {

	motorSpeeds[INDEX_FL_H] = 0;                             // set front left horizontal motor speed to zero
	motorSpeeds[INDEX_FR_H] = 0;                             // set front right horizontal motor speed to zero
	motorSpeeds[INDEX_BL_H] = 0;                             // set back left horizontal motor speed to zero
	motorSpeeds[INDEX_BR_H] = 0;                             // set back right horizontal motor speed to zero
	motorSpeeds[INDEX_FL_V] = 0;                             // set front left vertical motor speed to zero
	motorSpeeds[INDEX_FR_V] = 0;                             // set front right vertical motor speed to zero
	motorSpeeds[INDEX_BL_V] = 0;                             // set back left vertical motor speed to zero
	motorSpeeds[INDEX_BR_V] = 0;                             // set back right vertical motor speed to zero

}


// check motor speed is within valid range
void checkSpeedRange(int *motorSpeed) {
  
  if(*motorSpeed > 100) {*motorSpeed = 100;}              // limit maximum for positive motor speed
  if(*motorSpeed < -100) {*motorSpeed = -100;}            // limit maximum for negative motor speed

}























////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// motor calibration code  ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
/* Use with serial monitor by uncommenting special flag in config file
 * To account for incorrect wiring of the motors to ESCs, instead of changing the pins on the onboard code to be correct
 * it is much easier to just re-arrange the serial data buffer (change the order in which motor speeds are sent)
 * 
 * For example: if motor 6 is connected to the ESC for motor 8, by sending the speed for motor 6 in the position of the speed for motor 8
 * in the serial comms buffer motor 6 will drive at the correct speed
 *
 * Running this calibration allows the correct index numbers for the motor speeds to be determined so that
 * each speed is sent in the correct order in the serial data buffer
*/
void calibrateMotors() {

  // start
  Serial.println("\nBeginning Motor Calibration\n");
  int8_t motorIndices[8] = {0,0,0,0,0,0,0,0};
  int8_t motorDirections[8] = {0,0,0,0,0,0,0,0};

  resetMotorSpeeds();
  sendData(motorSpeeds, magnetStates);
  delay(2000);

  // run motor index checks
  Serial.println("------------------------");
  Serial.println("\nBeginning index checks\n");
  Serial.println("Test for front left horizontal motor (FL_H)");
  motorIndices[0] = findMotorIndex();
  Serial.println("Test for front right horizontal motor (FR_H)");
  motorIndices[1] = findMotorIndex();
  Serial.println("Test for back left horizontal motor (BL_H)");
  motorIndices[2] = findMotorIndex();
  Serial.println("Test for back right horizontal motor (BR_H)");
  motorIndices[3] = findMotorIndex();
  Serial.println("Test for front left vertical motor (FL_V)");
  motorIndices[4] = findMotorIndex();
  Serial.println("Test for front right vertical motor (FR_V)");
  motorIndices[5] = findMotorIndex();
  Serial.println("Test for back left vertical motor (BL_V)");
  motorIndices[6] = findMotorIndex();
  Serial.println("Test for back right vertical motor (BR_V)");
  motorIndices[7] = findMotorIndex();
  Serial.println("\nEnd index checks\n");
  Serial.println("------------------------");

  // run motor direction tests
  Serial.println("\nBeginning direction checks\n");
  
  
  Serial.println("Test for front left vertical motor (FL_V)");
  motorDirections[4] = findMotorDirection('c');                   // clockwise



  Serial.println("\nEnd direction checks\n");
  Serial.println("------------------------");

  // print results
  Serial.println("\nResults");
  Serial.print("#define INDEX_FL_H    ");
  Serial.println(motorIndices[0]);
  Serial.print("#define INDEX_FR_H    ");
  Serial.println(motorIndices[1]);
  Serial.print("#define INDEX_BL_H    ");
  Serial.println(motorIndices[2]);
  Serial.print("#define INDEX_BR_H    ");
  Serial.println(motorIndices[3]);
  Serial.print("#define INDEX_FL_V    ");
  Serial.println(motorIndices[4]);
  Serial.print("#define INDEX_FR_V    ");
  Serial.println(motorIndices[5]);
  Serial.print("#define INDEX_BL_V    ");
  Serial.println(motorIndices[6]);
  Serial.print("#define INDEX_BR_V    ");
  Serial.println(motorIndices[7]);

  
  // hold
  while(true) {
    ;
  }
  
}



uint8_t findMotorIndex() {
  
  // find what index in comms buffer has to be written to
  // for each motor to get it to turn
  bool testComplete = false;
  bool userResponded = false;
  int8_t motorTestSpeed = 10;
  int8_t result = -1;

    // loop through all possible motors
    for(uint8_t i = 0; i < 8; i++) {

      if(!testComplete) {
        // set all motor speeds to zero
        resetMotorSpeeds();
  
        // set correct motor on and send speed to onboard
        motorSpeeds[i] = motorTestSpeed;
        sendData(motorSpeeds, magnetStates);
  
        //wait for user input
        Serial.println("Is correct motor turning? y/n");
  
        while(!userResponded) {
          
          char input = Serial.read();
          
          if(input == 'y') {
            userResponded = true;
            testComplete = true;
            result = i;
          }
  
          if(input == 'n') {
            userResponded = true;
            testComplete = false;
          }
      
        }
        
        userResponded = false;
          
      }

    }

  Serial.println();
  return result;
  
}



uint8_t findMotorDirection(char desiredDirection) {

  // test direction produces +ve thrust
  bool testComplete = false;
  bool userResponded = false;
  int8_t motorTestSpeed = 25;
  int8_t result = -1;

  // set all motor speeds to zero
  resetMotorSpeeds();

}










