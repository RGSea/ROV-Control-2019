// electromagnet control code


// write outputs to electromagnet pins
void writeToElectromagnets() {

	digitalWrite(PIN_MAG_1, magnetStates[0]);		// write to electromagnet 1 pin
	digitalWrite(PIN_MAG_2, magnetStates[1]);		// write to electromagnet 2 pin
	digitalWrite(PIN_MAG_3, magnetStates[2]);		// write to electromagnet 3 pin
	digitalWrite(PIN_MAG_4, magnetStates[3]);		// write to electromagnet 4 pin
	digitalWrite(PIN_MAG_5, magnetStates[4]);		// write to electromagnet 5 pin
	digitalWrite(PIN_MAG_6, magnetStates[5]);		// write to electromagnet 6 pin

}
