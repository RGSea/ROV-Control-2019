// communications code


// initialisation code
void initComms() {

	Serial.begin(BAUDRATE);															// begin serial comms to laptop at baudrate
	Serial1.begin(BAUDRATE);														// begin serial comms to onboard at baudrate

}


// data formatter (output format: ixxxyyyzzzjjjkkk ... (initialiser character + 8 x 3 digit motor speeds in range 0-200))
void formatData(int motorSpeeds[8], String *formattedData) {

	// shift zero position of motor speeds up by 100
	for(int i = 0; i < 8; i++) {													// loop through motor speeds
		motorSpeeds[i] += 100;														// add 100 to each one so that range is 0-200 with 100 >> 0
	}

	// format data
	*formattedData = "i";															// start formatted data buffer with initialiser character
	for(int i = 0; i < 8; i++) {													// loop through motor motor speeds
		*formattedData += intToString(motorSpeeds[i]);								// convert each motor speed to a string and append to formatted data buffer
	}

}


// integer to string converter for motor speeds
String intToString(int val) {

	String zero = "0";																// zero string for empty digits
	String str;																		// output string to return

	// format integer into 3 character string
    if(val < 10 and val >= 0) {str = zero + zero + val;}							// if value < 10, string is 00 + the value
    if(val < 100 and val >= 10) {str = zero + val;}									// if value between 10 and 100, string is 0 + value
    if(val < 1000 and val >= 100) {str = val;}										// if value between 100 and 1000, string is value
    if(val < 0 or val >= 1000) {str = "000";}										// if value is zero or out of range, string is 000

    return str;																		// return formatted string

}


// send serial data
void sendData(int motorSpeeds[8]) {

	String formattedData = "i000000000000000000000000";								// blank data buffer
	
	// format and send data
	formatData(motorSpeeds, &formattedData);										// format motor speeds data
	Serial1.print(formattedData);													// send formatted data to onboard through serial port 1
	Serial1.print('\n');															// send newline terminator character to onboard through serial port 1


}


