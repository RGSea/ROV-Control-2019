// ESC Testing Code
/*
- Connect ESC to Arduino ground and pin 9 for signal
- Connect ESC to 12V ROV power supply
- Connect potentiometer across 5V and ground, connect centre pin to A5
- Calibrate ESCs if necessary
 */

#include <Servo.h>
Servo ESC;

#define BAUDRATE        115200
#define POT_PIN         5
#define ESC_PIN         9
#define MIN_MICROS      1064
#define MAX_MICROS      1864
#define NEUTRAL_MICROS  1464 
#define SPEED_LIMIT     1.00


void setup() {

  pinMode(POT_PIN, INPUT);
  pinMode(ESC_PIN, OUTPUT);
  Serial.begin(BAUDRATE);
  Serial.print("\nBeginning ESC test\n");
  ESC.attach(ESC_PIN);
  ESC.write(NEUTRAL_MICROS);
  Serial.print("Written neutral to ESC\n");
  Serial.print("Setup complete\n");
  delay(1000);

}


void loop() {

  uint16_t inputVal = analogRead(POT_PIN) * SPEED_LIMIT;
  uint16_t outputVal = map(inputVal, 0, 1023, MIN_MICROS, MAX_MICROS);
  Serial.print("output: ");
  Serial.println(outputVal);
  ESC.writeMicroseconds(outputVal);

}





