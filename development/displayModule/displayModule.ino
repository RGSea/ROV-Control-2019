// include libraries
#include <LiquidCrystal.h>
#include <Encoder.h>
#include <Keypad.h>


// define LCD pin numbers
#define PIN_LCD_RESET   12    // grey wire 1
#define PIN_LCD_ENABLE  11    // blue wire
#define PIN_LCD_DATA_1  8     // purple wire
#define PIN_LCD_DATA_2  4     // green wire
#define PIN_LCD_DATA_3  3     // orange wire
#define PIN_LCD_DATA_4  2     // grey wire 2

// define encoder pin numbers and variables
#define PIN_ENC_1       5     // orange wire
#define PIN_ENC_2       6     // green wire
#define PIN_ENC_BUTTON  7     // brown wire
long oldPosition  = -1;
long newPosition = 0;

// encoder button debounce variables
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

// cannon calculation input parameters
uint8_t boreRadius = 0;
uint8_t smallEndRadius = 0;
uint8_t largeEndRadius = 0;
uint8_t height = 0;
double cannonVolume;
double cannonDensity;
double cannonWeightInAir;
double waterWeight;
double cannonWeight;



// define keypad constants
#define ROWS    4
#define COLS    3
byte rowPins[ROWS] = {A2, A1, A0, 9};
byte colPins[COLS] = {A5, A4, A3};
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'n','0','y'}
};

// define menu variables
uint8_t menuPosition = 0;
uint8_t subMenuPosition = 0;
bool mainMenu = true;
bool subMenu = false;


// initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to
LiquidCrystal LCD(PIN_LCD_RESET, PIN_LCD_ENABLE, PIN_LCD_DATA_1, PIN_LCD_DATA_2, PIN_LCD_DATA_3, PIN_LCD_DATA_4);
Encoder encoder(PIN_ENC_1, PIN_ENC_2);
Keypad numpad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

// variables

void setup() {
  
  LCD.begin(16, 2);                              // set up the LCD's number of columns and rows
  LCD.clear();                                   // clear LCD
  pinMode(PIN_ENC_BUTTON, INPUT_PULLUP);         // set pin mode for encoder button pin
  Serial.begin(9600);

}

void loop() {

  updateLCD();


  
}


void updateLCD() {

  const char mainMenuStrings[4][16] {"0 - Sensors     ", "1 - Cannon Calc.", "2 - Status      ", "3 - Settings    "};
  const char subMenuStrings[4][16] = {"Sensor Readouts ", "Cannon Calc.    ", "Status          ", "Settings        s"};

  int change = encoderChange();
  
  
  // switch debouncing code
  int reading = 1 - digitalRead(PIN_ENC_BUTTON);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        mainMenu = !mainMenu;
      }
    }
  }

  lastButtonState = reading;
  

  // print the main menu
  if(mainMenu) {
    
    menuPosition += change;
    if(menuPosition < 0)  {menuPosition = 0;}
    if(menuPosition > 3) {menuPosition = 3;}
    
    LCD.setCursor(0,0);
    LCD.print("Main Menu:      ");
    
    LCD.setCursor(0,1);
    
    for(uint8_t i = 0; i < 16; i++) {
      LCD.print(mainMenuStrings[menuPosition][i]);
    }
  }


  // print sub menu
  if(!mainMenu) {

    LCD.setCursor(0,0);
    for(uint8_t i = 0; i < 16; i++) {
      LCD.print(subMenuStrings[menuPosition][i]);
    }

    subMenuPosition += change;
    if(subMenuPosition < 0)  {subMenuPosition = 0;}
    if(subMenuPosition > 10) {subMenuPosition = 10;}
    LCD.setCursor(0,1);
    
    switch(menuPosition){

      case 0:
        LCD.print("Temp: ");
        LCD.print(getTempReading());
        LCD.print(char(223));
        LCD.print("C     ");
        break;

      case 1:

        char input;
        input = keyPress();
      
        switch(subMenuPosition) {

          case 0:
            LCD.print("rBore=");
            if(input != 'x') {
              boreRadius = input - '0';             
            }
            LCD.print(boreRadius);
            LCD.print("cm        "); 
            break;

          case 1:
            LCD.print("rSmall=");
            if(input != 'x') {
              smallEndRadius = input - '0';             
            }
            LCD.print(smallEndRadius);
            LCD.print("cm        "); 
            break;

          case 2:
            LCD.print("rLarge=");
            if(input != 'x') {
              largeEndRadius = input - '0';             
            }
            LCD.print(largeEndRadius);
            LCD.print("cm        "); 
            break;

          case 3:
            LCD.print("height=");
            if(input != 'x') {
              height = input - '0';             
            }
            LCD.print(height);
            LCD.print("cm        "); 
            break;

          case 4:
            LCD.print("<calculate>     ");
            break;

          default:
            break;
        }
        break;
        
      default:
        break;
    }

    
  }

  
}


int getTempReading() {
  return 24;
}



char keyPress() {
  
  char customKey = numpad.getKey();
  
  if (customKey){
    return customKey;
  }
  else {
    return 'x';
  }
  
}


bool encoderButtonState() {
  bool state = digitalRead(PIN_ENC_BUTTON);       // get button state by reading from pin
  return (1 - state);                             // make it so return 1  pressed and return 0 unpressed
}


int encoderPosition() {

  newPosition = encoder.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
  }
  
  return (int(-newPosition/4));
}

int encoderChange() {

  newPosition = int(encoder.read() / 4);
  int change = -(newPosition - oldPosition);
  oldPosition = newPosition;
  Serial.println(change);
  return change;

}





