

void initComms() {
	Serial.begin(BAUDRATE);
}


void serialEvent() {

	// update input data if new data has arrived
  	while(Serial.available()) {
	    char inChar = (char)Serial.read();
	    dataIn += inChar;
	    if (inChar == '\n') {
	     	dataPacketRecieved = true;
	    }
  	}

  recvData();

}


void recvData() {

	// format data if full packet recieved
	if(dataPacketRecieved) {
		#ifdef DEBUG_COMMS
			Serial.println(dataIn);
		#endif
		formatData();
		dataIn = "";
		dataPacketRecieved = false;
	}

}


void formatData() {

	// crop initialiser bit from string
	dataIn = dataIn.substring(1);
  Serial.println(dataIn);

  
  //char buffer[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  //dataIn.toCharArray(buffer, 24);

	// split data into substrings and update motor speeds
	//motorSpeeds[0] = dataIn.substring(0,0).toInt();
  //Serial.println(dataIn);
	
	
	/*int index;
	for(int i = 0; i < 8; i++) {
		index = i * 3;
		motorSpeeds[i] = dataIn.substring(index, index + 3).toInt() - 100;
	}*/


	// debug code
	#ifdef DEBUG_MOTOR_SPEEDS
		for(int i = 0; i < 8; i++) {
			Serial.print(motorSpeeds[i]);
			Serial.print("\t");
		}
		Serial.println();
	#endif

}
