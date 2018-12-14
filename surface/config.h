// configuration file
// defines all constant parameters as macros

// serial comms
#define BAUDRATE		115200

// motor index numbers
#define INDEX_FL_H    1
#define INDEX_FR_H    7
#define INDEX_BL_H    2
#define INDEX_BR_H    4
#define INDEX_FL_V    0
#define INDEX_FR_V    6
#define INDEX_BL_V    3
#define INDEX_BR_V    5


// reverse motors
#define REVERSE_FL_H  false
#define REVERSE_FR_H  false
#define REVERSE_BL_H  false
#define REVERSE_BR_H  false
#define REVERSE_FL_V  false
#define REVERSE_FR_V  true
#define REVERSE_BL_V  true
#define REVERSE_BR_V  true

// control parameters
#define DEADZONE      15
#define AXIS_MIN      -32767
#define AXIS_MAX      32767
#define ROOT2         1.4142
#define YAWRATE       10
#define MAX_GAIN_VAL  100
#define SPEED_LIMIT   1

// pins
#define ENCODER_PIN_1	2		// must be interrupt capable
#define ENCODER_PIN_2	3		// must be interrupt capable
#define SWITCH_PIN    4   // DDR needs to be input pullup

// debug
//#define DEBUG_VERTICAL_MOTOR_SPEEDS
//#define DEBUG_HORIZONTAL_MOTOR_SPEEDS
//#define CALIBRATE_MOTORS














