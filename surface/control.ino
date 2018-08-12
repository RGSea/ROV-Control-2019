// control algorithm

void calcMotorSpeeds() {

	motorSpeeds(INDEX_FL_H) = 0;
	motorSpeeds(INDEX_FR_H) = 0;
	motorSpeeds(INDEX_BL_H) = 0;
	motorSpeeds(INDEX_BR_H) = 0;
	motorSpeeds(INDEX_FL_V) = 0;
	motorSpeeds(INDEX_FR_V) = 0;
	motorSpeeds(INDEX_BL_V) = 0;
	motorSpeeds(INDEX_BR_V) = 0;

}


void resetMotorSpeeds() {

	motorSpeeds(INDEX_FL_H) = 0;
	motorSpeeds(INDEX_FR_H) = 0;
	motorSpeeds(INDEX_BL_H) = 0;
	motorSpeeds(INDEX_BR_H) = 0;
	motorSpeeds(INDEX_FL_V) = 0;
	motorSpeeds(INDEX_FR_V) = 0;
	motorSpeeds(INDEX_BL_V) = 0;
	motorSpeeds(INDEX_BR_V) = 0;

}