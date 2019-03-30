#include "config.h"

float getTempValue() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  return temp;
}

/*
int16_t applyTempCalibration(int16_t temp) {

  temp = temp;
  return temp;
}
*/


