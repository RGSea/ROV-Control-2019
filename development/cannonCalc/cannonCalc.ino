#include <LiquidCrystal.h>

// calculation constants
#define PI                  3.141592653 //
#define DENSITY_WATER       997         // kg/m^3
#define SPECIFIC_GRAVITY    2           //
#define g                   9.81        // m/s^2

// program constants
#define BAUDRATE            115200      // data rate for serial comms

#define rs  12
#define en  11 
#define d4  5 
#define d5  4 
#define d6  3 
#define d7  2


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// setup code
void setup() {
  
  Serial.begin(115200);
  Serial.println("-----cannon calculator-----");
  
  lcd.begin(16,2);
  lcd.print("Hello");
}


// main loop
void loop() {

  lcd.setCursor(0,1);
  lcd.print(millis() / 1000);







}





void runCannonCalc() {


  Serial.println("\n-----input parameters------");

  // calculation input parameters
  double boreRadius = 1;
  double smallEndRadius = 2;
  double largeEndRadius = 4;
  double height = 4;

  double cannonVolume;
  double cannonDensity;
  double cannonWeightInAir;
  double waterWeight;
  double cannonWeight;


  Serial.print("bore radius\t\t");
  Serial.println(boreRadius);
  Serial.print("small end radius:\t");
  Serial.println(smallEndRadius);
  Serial.print("large end radius:\t");
  Serial.println(largeEndRadius);
  Serial.print("height:\t\t\t");
  Serial.println(height);
  Serial.println();

  // calculation of cannon volume
  cannonVolume = ((PI * height) / 3) * ((smallEndRadius * smallEndRadius) + (smallEndRadius * largeEndRadius) + (largeEndRadius * largeEndRadius) - (3 * boreRadius * boreRadius));

  Serial.println("-----results-----");
  Serial.print("cannon volume: \t\t\t");
  Serial.println(cannonVolume);

  // calculation of cannon weight
  cannonDensity = SPECIFIC_GRAVITY * DENSITY_WATER;
  cannonWeightInAir = cannonVolume * cannonDensity * g;

  Serial.print("cannon weight in air: \t\t");
  Serial.println(cannonWeightInAir);


  // calculation of weight of water displaced
  waterWeight = DENSITY_WATER * cannonVolume * g;

  Serial.print("weight of water displaced: \t");
  Serial.println(waterWeight);
  
  // calculation of effective weight
  cannonWeight = cannonWeightInAir - waterWeight;

  Serial.print("cannon weight: \t\t\t");
  Serial.println(cannonWeight);

  delay(100000000);

}
