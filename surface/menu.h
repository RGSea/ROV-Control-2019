#pragma once
#ifndef MENU_H
#define MENU_H

#include "Arduino.h"
#include "config.h"


uint8_t updateGain(double *gainVal, int change) {

	Serial.println(*gainVal);

	*gainVal += (change * 0.1);

	if(*gainVal < 0) {
		*gainVal = 0;
	}
	if(*gainVal > MAX_GAIN_VAL) {
		*gainVal = MAX_GAIN_VAL;
	}

	return 0;
}










class menuPage {
	public:
		menuPage();

	private:
		uint8_t position = 0;
		char menuItems[10] = {"","","",""};


};



menuPage::menuPage() {
	;
}





#endif


