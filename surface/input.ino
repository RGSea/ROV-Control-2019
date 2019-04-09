// control input


// initialisation code
void initControlInput() {
  
  Serial.begin(BAUDRATE);                                           // begin serial comms at baudrate specified in config

  #if !defined(__MIPSEL__)                                          // catch for XBUXUSB 
    while (!Serial);                                                // wait for serial connection
  #endif                                                            // end of XBUXUSB catch

  if (Usb.Init() == -1) {                                           // check if USB connection failed
    Serial.print(F("\r\nUSB did not start"));                       // print USB failed if true
    while(1);                                                       // stop if connection failed
  }

  Serial.print(F("\r\nXBOX USB Library Started"));                  // print XBOX USB status

}


// fetch control input from XBOX controller
void fetchControlInput() {
  
  Usb.Task();                                                       // poll USB device
  
  if(Xbox.Xbox360Connected) {                                       // check if controller connected

    Lx = mapAxis(Xbox.getAnalogHat(LeftHatX));                      // fetch and map left joystick x axis value
    Ly = mapAxis(Xbox.getAnalogHat(LeftHatY));                      // fetch and map left joystick y axis value
    Rx = mapAxis(Xbox.getAnalogHat(RightHatX));                     // fetch and map right joystick x axis value
    Ry = mapAxis(Xbox.getAnalogHat(RightHatY));                     // fetch and map right joystick y axis value

    LT = Xbox.getButtonPress(L2) / 2.55;                            // fetch and scale left trigger axis value
    RT = Xbox.getButtonPress(R2) / 2.55;                            // fetch and scale right trigger axis value

    LB = Xbox.getButtonPress(L1);                                   // fetch left bumper button state
    RB = Xbox.getButtonPress(R1);                                   // fetch right bumper button state

    deadzoneCheck(&Lx);                                             // deadzone check left joystick x axis
    deadzoneCheck(&Ly);                                             // deadzone check left joystick y axis
    deadzoneCheck(&Rx);                                             // deadzone check right joystick x axis
    deadzoneCheck(&Ry);                                             // deadzone check right joystick y axis
    
  }
  
}


// map joystick axis
int mapAxis(int axis) {
  
  axis = map(axis, -32767, 32767, -100, 100);                       // map axis to range -100 to 100
  return axis;                                                      // return mapped value
  
}


// check if axis is in deadzone
void deadzoneCheck(int32_t   *axis) {
  
  if(*axis <= DEADZONE && *axis >= -DEADZONE) {                     // check if axis is within deadzone
    *axis = 0;                                                      // set axis to zero if within deazone
  }
  else {                                                            // if not in deadzone
    if(*axis > DEADZONE) {                                          // if in positive direction
      *axis = map(*axis, DEADZONE, 100, 0, 100);                    // re-map axis accordingly
    }
    if(*axis < -DEADZONE) {                                         // if in negative direction
      *axis = map(*axis, -DEADZONE, -100, 0, -100);                 // re-map axis accordingly
    }
  }
  
}




