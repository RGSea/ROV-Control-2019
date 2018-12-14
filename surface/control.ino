// control algorithm

void calcMotorSpeeds() {

	// local variables for calculation
	int altitude = RT - LT;
	int pitch = Ry;
	int roll = Rx;
  int inPut = sqrt((Lx*Lx)+(Ly*Ly));

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


  // check speed range and apply power limiting factor to all motors
  for(uint8_t i = 0; i < 8; i++) {
    checkSpeedRange(&motorSpeeds[i]);
    motorSpeeds[i] = motorSpeeds[i] * SPEED_LIMIT;
  }

  // reverse motors if necessary
  if(REVERSE_FL_H) {motorSpeeds[INDEX_FL_H] = -1 * motorSpeeds[INDEX_FL_H];}
  if(REVERSE_FR_H) {motorSpeeds[INDEX_FR_H] = -1 * motorSpeeds[INDEX_FR_H];}
  if(REVERSE_BL_H) {motorSpeeds[INDEX_BL_H] = -1 * motorSpeeds[INDEX_BL_H];}
  if(REVERSE_BR_H) {motorSpeeds[INDEX_BR_H] = -1 * motorSpeeds[INDEX_BR_H];}
  if(REVERSE_FL_V) {motorSpeeds[INDEX_FL_V] = -1 * motorSpeeds[INDEX_FL_V];}
  if(REVERSE_FR_V) {motorSpeeds[INDEX_FR_V] = -1 * motorSpeeds[INDEX_FR_V];}
  if(REVERSE_BL_V) {motorSpeeds[INDEX_BL_V] = -1 * motorSpeeds[INDEX_BL_V];}
  if(REVERSE_BR_V) {motorSpeeds[INDEX_BR_V] = -1 * motorSpeeds[INDEX_BR_V];}


	// print motor speeds if debug
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

}


void resetMotorSpeeds() {

	motorSpeeds[INDEX_FL_H] = 0;
	motorSpeeds[INDEX_FR_H] = 0;
	motorSpeeds[INDEX_BL_H] = 0;
	motorSpeeds[INDEX_BR_H] = 0;
	motorSpeeds[INDEX_FL_V] = 0;
	motorSpeeds[INDEX_FR_V] = 0;
	motorSpeeds[INDEX_BL_V] = 0;
	motorSpeeds[INDEX_BR_V] = 0;

}


void checkSpeedRange(int *motorSpeed) {
  if(*motorSpeed > 100) {
    *motorSpeed = 100;
  }
  if(*motorSpeed < -100) {
    *motorSpeed = -100;
  }
}




// motor calibration function

void calibrateMotors() {

  // start
  Serial.println("\nBeginning Motor Calibration\n");
  int8_t motorIndices[8] = {0,0,0,0,0,0,0,0};
  int8_t motorDirections[8] = {0,0,0,0,0,0,0,0};

  resetMotorSpeeds();
  sendData(motorSpeeds);
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
        sendData(motorSpeeds);
  
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










