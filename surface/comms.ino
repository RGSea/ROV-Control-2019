// communications code

void initComms() {
	Serial.begin(BAUDRATE);
	Serial1.begin(BAUDRATE);
}


void formatData(int motorSpeeds[8], String *formattedData) {

	// shift zero position of motor speeds
	for(int i = 0; i < 8; i++) {
		motorSpeeds[i] += 100;
	}

	// format data
	*formattedData = "i";
	for(int i = 0; i < 8; i++) {
		*formattedData += intToString(motorSpeeds[i]);
	}

}


String intToString(int val) {

	// local variables
	String zero = "0";
	String str;

	// format integer into 3 character string
    if(val < 10 and val >= 0) {str = zero + zero + val;}
    if(val < 100 and val >= 10) {str = zero + val;}
    if(val < 1000 and val >= 100) {str = val;}
    if(val < 0 or val >= 1000) {str = "000";}

    // return formatted string
    return str;

}


void sendData(int motorSpeeds[8]) {

	// local variables
	String formattedData = "i000000000000000000000000";
	
	// format and send data
	formatData(motorSpeeds, &formattedData);
	//Serial.println(formattedData);
	Serial1.print(formattedData);
	Serial1.print('\n');


}
