// control algorithm

void calcMotorSpeeds() {

	// local variables
	int altitude = RT - LT;
	int pitch = Ry;
	int roll = Rx;

	// calculate vertical motor speeds
	motorSpeeds[INDEX_FL_V] = altitude - pitch + roll;
	motorSpeeds[INDEX_FR_V] = altitude - pitch - roll;
	motorSpeeds[INDEX_BL_V] = altitude + pitch + roll;
	motorSpeeds[INDEX_BR_V] = altitude + pitch - roll;

	// calculate horizontal motor speeds
  motorSpeeds[INDEX_FR_H] = ( (ROOT2/2) * (Lx-Ly) ) / 0.7 + (YAWRATE * RB) - (YAWRATE * LB);
  motorSpeeds[INDEX_FL_H] = ( (ROOT2/2) * (-Lx-Ly)) / 0.7 - (YAWRATE * RB) + (YAWRATE * LB);
  motorSpeeds[INDEX_BR_H] = ( (ROOT2/2) * (Lx+Ly) ) / 0.7 - (YAWRATE * RB) + (YAWRATE * LB);
  motorSpeeds[INDEX_BL_H] = (-(ROOT2/2) * (Lx-Ly) ) / 0.7 + (YAWRATE * RB) - (YAWRATE * LB);

  // verify speeds are in range (some will not be)
  checkSpeedRange(&motorSpeeds[INDEX_FL_H]);
  checkSpeedRange(&motorSpeeds[INDEX_FR_H]);
  checkSpeedRange(&motorSpeeds[INDEX_BL_H]);
  checkSpeedRange(&motorSpeeds[INDEX_BR_H]);
  checkSpeedRange(&motorSpeeds[INDEX_FL_V]);
  checkSpeedRange(&motorSpeeds[INDEX_FR_V]);
  checkSpeedRange(&motorSpeeds[INDEX_BL_V]);
  checkSpeedRange(&motorSpeeds[INDEX_BR_V]);

/*
  Serial.print("\t");
  Serial.print(motorSpeeds[INDEX_FL_H]);
  Serial.print("\t");
  Serial.print(motorSpeeds[INDEX_FR_H]);
  Serial.print("\t\t");
  Serial.print(motorSpeeds[INDEX_BL_H]);
  Serial.print("\t");
  Serial.println(motorSpeeds[INDEX_BR_H]);
*/


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





