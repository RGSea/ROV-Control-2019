// configuration file
// defines all constant parameters as macros


// trim & adjustments

#define ALTITUDE_TRIM   10                            // maximum altitude trim level as a percentage
#define ROLL_TRIM       10                            // maximum roll trim level as a percentage
#define PITCH_TRIM      10                            // maximum pitch trim level as a percentage
#define SPEED_LIMIT     1                             // software speed limiting factor (0-1)
#define YAWRATE         10



// control input
#define DEADZONE      15
#define AXIS_MIN      -32767
#define AXIS_MAX      32767
#define ROOT2         1.4142

// serial comms
#define BAUDRATE		115200

// motor index numbers
#define INDEX_FL_H    1
#define INDEX_FR_H    7
#define INDEX_BL_H    2
#define INDEX_BR_H    5
#define INDEX_FL_V    0
#define INDEX_FR_V    6
#define INDEX_BL_V    3
#define INDEX_BR_V    4

// potentiometer pin / index numbers
#define INDEX_PITCH_TRIM      12
#define INDEX_ROLL_TRIM       13
#define INDEX_MASTER_POWER    15
#define INDEX_ALTITUDE_TRIM   14


// reverse motors
#define REVERSE_FL_H  false
#define REVERSE_FR_H  true
#define REVERSE_BL_H  true
#define REVERSE_BR_H  false
#define REVERSE_FL_V  false
#define REVERSE_FR_V  true
#define REVERSE_BL_V  true
#define REVERSE_BR_V  true

// pins
#define ENCODER_PIN_1	2		// must be interrupt capable
#define ENCODER_PIN_2	3		// must be interrupt capable
#define SWITCH_PIN    4   // DDR needs to be input pullup

// debug
//#define DEBUG_VERTICAL_MOTOR_SPEEDS
//#define DEBUG_HORIZONTAL_MOTOR_SPEEDS
//#define DEBUG_TRIM_VALUES
//#define CALIBRATE_MOTORS














