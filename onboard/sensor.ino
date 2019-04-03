// temp sensor code in development


#include "config.h"

float getTempValue() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  return temp;
}



