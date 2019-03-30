#pragma once
#ifndef MENU_H
#define MENU_H

#include "Arduino.h"
#include "config.h"










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


