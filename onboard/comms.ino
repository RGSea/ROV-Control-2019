// communications handling code


// initialisation for serial comms
void initComms() {

	Serial.begin(BAUDRATE);															// begin serial comms at baudrate specified in config file

}


// serial event listener (interrupt driven)
void serialEvent() {

	// update input buffer if new data has arrived
  	while(Serial.available()) {														// go through all incoming serial packets
	    
	    char inChar = (char)Serial.read();											// read input character from serial buffer
	    dataIn += inChar;															// append input character to input data
	    
	    if (inChar == '\n') {														// listen for transmission terminator character
	     	dataPacketRecieved = true;												// signal end of transmission if terminator recieved
	    }

  	}

  recvData();																		// run data packet handling

}


// data packet handler
void recvData() {

	// format data if full packet recieved, else ignore
	if(dataPacketRecieved) {														// check if complete packet has been recieved
		
		#ifdef DEBUG_COMMS															// check for debug flag
			Serial.println(dataIn);													// print data to serial port TX if flag activated
		#endif																		// end of debug flag code

		formatData();																// run data formatter

		dataIn = "";																// clear data input buffer ready for next packet
		dataPacketRecieved = false;													// reset data packet reception packet
	}

}


// data formatter
void formatData() {

	dataIn = dataIn.substring(1);													// crop initialiser bit from string
	uint16_t index;																	// define temporary index variable
	
	// read in new data to motor speeds array
	for(uint8_t i = 0; i < 8; i++) {												// loop through input data substrings
		
		index = i * 3;																// detemine index of input string to read from
		motorSpeeds[i] = dataIn.substring(index, index + 3).toInt() - 100;			// read substring into motor speeds, convert to integer in range -100 to 100

	}

	#ifdef DEBUG_MOTOR_SPEEDS														// check for debug flag
		for(uint8_t i = 0; i < 8; i++) {											// loop through motor speeds
			Serial.print(motorSpeeds[i]);											// print motor speed
			Serial.print("\t");														// print tab spacer
		}
		Serial.println();															// print newline
	#endif																			// end of debug flag

}
