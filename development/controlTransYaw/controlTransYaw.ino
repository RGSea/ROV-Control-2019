//control algorithm for translation and yaw
// global variables
  int motorSpeeds[8] = {10,50,30,40,50,60,70,80};
  int Lx, Ly, Rx, Ry, LT, RT;
  bool LB, RB;

void setup() {
}

void loop() {

  //define local variables
  int yawRate = 10;
  float root2 = 1.4;
  
  //checking for input of 100 or -100 from Lx
  switch (Lx) {
    case 100
    motorSpeeds[INDEX_FR_H] = 100 - yawRate + (yawRate*RB) - (yawRate*LB);
    motorSpeeds[INDEX_FL_H] = -100 + yawRate - (yawRate*RB) + (yawRate*LB);
    motorSpeeds[INDEX_BR_H] = 100 - yawRate - (yawRate*RB) + (yawRate*LB);
    motorSpeeds[INDEX_BL_H] = -100 + yawRate + (yawRate*RB) - (yawRate*LB);
    break;

    case -100
    motorSpeeds[INDEX_FR_H] = -100 + yawRate + (yawRate*RB) - (yawRate*LB);
    motorSpeeds[INDEX_FL_H] = 100 - yawRate - (yawRate*RB) + (yawRate*LB);
    motorSpeeds[INDEX_BR_H] = -100 + yawRate - (yawRate*RB) + (yawRate*LB);
    motorSpeeds[INDEX_BL_H] = 100 - yawRate + (yawRate*RB) - (yawRate*LB);
    break;

  }

  //checking for input of 100 or -100 from Ly
  switch (Ly) {
    case 100
    motorSpeeds[INDEX_FR_H] = -100 + yawRate + (yawRate*RB) - (yawRate*LB);
    motorSpeeds[INDEX_FL_H] = -100 + yawRate - (yawRate*RB) + (yawRate*LB);
    motorSpeeds[INDEX_BR_H] = 100 - yawRate - (yawRate*RB) + (yawRate*LB);
    motorSpeeds[INDEX_BL_H] = 100 - yawRate + (yawRate*RB) - (yawRate*LB);
    break;

    case -100
    motorSpeeds[INDEX_FR_H] = 100 - yawRate + (yawRate*RB) - (yawRate*LB);
    motorSpeeds[INDEX_FL_H] = 100 - yawRate - (yawRate*RB) + (yawRate*LB);
    motorSpeeds[INDEX_BR_H] = -100 + yawRate - (yawRate*RB) + (yawRate*LB);
    motorSpeeds[INDEX_BL_H] = -100 + yawRate + (yawRate*RB) - (yawRate*LB);
    break;
    
  }

  //if not 100 or -100 on any axis formula below is used
  motorSpeeds[INDEX_FR_H] = int (root2/2)*(Lx-Ly) + (yawRate*RB) - (yawRate*LB);
  motorSpeeds[INDEX_FL_H] = int (root2/2)*(-Lx-Ly) - (yawRate*RB) + (yawRate*LB);
  motorSpeeds[INDEX_BR_H] = int (root2/2)*(Lx+Ly) - (yawRate*RB) + (yawRate*LB);
  motorSpeeds[INDEX_BL_H] = int (root2/2)*(Lx-Ly) + (yawRate*RB) - (yawRate*LB);

  //checking for values greater than 100
  if (motorSpeeds[INDEX_FR_H]) > 100 {
    motorSpeeds[INDEX_FR_H] = 100;
  }
  if (motorSpeeds[INDEX_FR_H]) < -100 {
    motorSpeeds[INDEX_FR_H] = -100;
  }
  if (motorSpeeds[INDEX_FL_H]) > 100 {
    motorSpeeds[INDEX_FL_H] = 100;
  }
  if (motorSpeeds[INDEX_FL_H]) < -100 {
    motorSpeeds[INDEX_FL_H] = 100;
  }
  if (motorSpeeds[INDEX_BR_H]) > 100 {
    motorSpeeds[INDEX_BR_H] = 100;
  }
  if (motorSpeeds[INDEX_BR_H]) < -100 {
    motorSpeeds[INDEX_BR_H] = -100;
  }
  if (motorSpeeds[INDEX_BL_H]) > 100 {
    motorSpeeds[INDEX_BL_H] = 100;
  }
  if (motorSpeeds[INDEX_BL_H]) < 100 {
    motorSpeeds[INDEX_BL_H] = -100;
  }

    
}
