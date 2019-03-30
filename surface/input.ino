// control input

void initControlInput() {
  
  Serial.begin(BAUDRATE);
  #if !defined(__MIPSEL__)
    while (!Serial);
  #endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nUSB did not start"));
    while(1);
  }
  Serial.print(F("\r\nXBOX USB Library Started"));  

}

void fetchControlInput() {
  
  Usb.Task();
  
  if(Xbox.Xbox360Connected) {
    Lx = mapAxis(Xbox.getAnalogHat(LeftHatX));
    Ly = mapAxis(Xbox.getAnalogHat(LeftHatY));
    Rx = mapAxis(Xbox.getAnalogHat(RightHatX));
    Ry = mapAxis(Xbox.getAnalogHat(RightHatY));
    LT = Xbox.getButtonPress(L2) / 2.55;
    RT = Xbox.getButtonPress(R2) / 2.55;
    LB = Xbox.getButtonPress(L1);
    RB = Xbox.getButtonPress(R1);
    deadzoneCheck(&Lx);
    deadzoneCheck(&Ly);
    deadzoneCheck(&Rx);
    deadzoneCheck(&Ry);
    
  }
  
}


int mapAxis(int axis) {
  
  axis = map(axis, -32767, 32767, -100, 100);
  return axis;
  
}


void deadzoneCheck(int *axis) {
  
  if(*axis <= DEADZONE && *axis >= -DEADZONE) {
    *axis = 0;
  }
  else {
    if(*axis > DEADZONE) {
      *axis = map(*axis, DEADZONE, 100, 0, 100);
    }
    if(*axis < -DEADZONE) {
      *axis = map(*axis, -DEADZONE, -100, 0, -100);
    }
  }
  
}




