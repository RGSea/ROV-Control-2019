

void initESCs() {

	// attach pins to ESC objects
	FL_H.attach(PIN_FL_H);
	FR_H.attach(PIN_FR_H);
	BL_H.attach(PIN_BL_H);
	BR_H.attach(PIN_BR_H);
	FL_V.attach(PIN_FL_V);
	FR_V.attach(PIN_FR_V);
	BL_V.attach(PIN_BL_V);
	BR_V.attach(PIN_BR_V);

	// write neutral speed to motors
	FL_H.writeMicroseconds(NEUTRAL_MICROS);
	FR_H.writeMicroseconds(NEUTRAL_MICROS);
	BL_H.writeMicroseconds(NEUTRAL_MICROS);
	BR_H.writeMicroseconds(NEUTRAL_MICROS);
	FL_V.writeMicroseconds(NEUTRAL_MICROS);
	FR_V.writeMicroseconds(NEUTRAL_MICROS);
	BL_V.writeMicroseconds(NEUTRAL_MICROS);
	BR_V.writeMicroseconds(NEUTRAL_MICROS);

}


int percentToMicros(int percent) {

	// map percentage speed to microsecond write
	return map(percent, -100, 100, MIN_MICROS, MAX_MICROS);

}


void writeToESCs() {
	
	// write motor speeds to ESCs
	FL_H.writeMicroseconds(percentToMicros(motorSpeeds[INDEX_FL_H]));
	FR_H.writeMicroseconds(percentToMicros(motorSpeeds[INDEX_FR_H]));
	BL_H.writeMicroseconds(percentToMicros(motorSpeeds[INDEX_BL_H]));
	BR_H.writeMicroseconds(percentToMicros(motorSpeeds[INDEX_BR_H]));
	FL_V.writeMicroseconds(percentToMicros(motorSpeeds[INDEX_FL_V]));
	FR_V.writeMicroseconds(percentToMicros(motorSpeeds[INDEX_FR_V]));
	BL_V.writeMicroseconds(percentToMicros(motorSpeeds[INDEX_BL_V]));
	BR_V.writeMicroseconds(percentToMicros(motorSpeeds[INDEX_BR_V]));

}