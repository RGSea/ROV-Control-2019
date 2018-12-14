// calculatiuon constants
#define PI                  3.14        //
#define DENSITY_WATER       997         // kg/m^3
#define SPECIFIC_GRAVITY  
#define g                   9.81        // m/s^2

// program constants
#define BAUDRATE            115200      // data rate for serial comms




void setup() {
  
  Serial.begin(115200);
  Serial.println("-----cannon calculator-----");
  

}

void loop() {

  // calculation input parameters
  double boreRadius = 1;
  double smallEndRadius = 1;
  double largeEndRadius = 1;
  double height;

  double cannonVolume;
  double cannonDensity;
  double cannonWeightInAir;
  double waterWeight;
  double cannonWeight;

  // calculation of cannon volume
  cannonVolume = ((PI * height) / 3) * ((smallEndRadius)^2 + (smallEndRadius * largeEndRadius) + (largeEndRadius)^2 - (3 * boreRadius^2));

  // calculation of cannon weight
  cannonDensity = SPECIFIC_GRAVITY * DENSITY_WATER;
  cannonWeightInAir = cannonVolume * cannonDensity * g;

  // calculation of weight of water displaced
  waterWeight = DENSITY_WATER * cannonVolume * g;
  
  // calculation of effective weight
  cannonWeight = cannonWeightInAir - waterWeight;

}
