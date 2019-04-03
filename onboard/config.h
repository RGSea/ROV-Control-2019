// configuration file for main program constants


// debug flags
/*
#define DEBUG_MOTOR_SPEEDS				// debug flag to print received motor speeds
#define DEBUG_COMMS						// debug flag to print raw comms data
#define PRINT_TEMP_VAL					// debug flag to print temperature sensor readout
*/

// serial comms
#define BAUDRATE		115200			// serial commms speed in bits/second

// ESCs
#define MIN_MICROS		1064			// minimum pulse length for ESCs			
#define MAX_MICROS		1864			// maximum pulse length for ESCs
#define NEUTRAL_MICROS	1464 			// neutral pulse length for ESCs

// ESC pin numbers
#define PIN_FL_H        6 				// front left horizontal ESC pin number
#define PIN_FR_H        7 				// front right horizontal ESC pin number
#define PIN_BL_H        8  				// back left horizontal ESC pin number
#define PIN_BR_H        9  				// back right horizontal ESC pin number
#define PIN_FL_V        10				// front left vertical ESC pin number 
#define PIN_FR_V        11				// front right vertical ESC pin number 
#define PIN_BL_V        12				// back left vertical ESC pin number 
#define PIN_BR_V        13				// back right vertical ESC pin number 

// electromagnet pin numbers
#define PIN_MAG_1		A0				// pin number for first tee electromagnet
#define PIN_MAG_2		A1				// pin number for second tee electromagnet
#define PIN_MAG_3		A2				// pin number for third tee electromagnet
#define PIN_MAG_4		A3				// pin number for fourth tee electromagnet
#define PIN_MAG_5		A4				// pin number for fish elegtromagnet
#define PIN_MAG_6		A5				// pin number for metal detector electromagnet

// motor index numbers
#define INDEX_FL_H		0				// front left horizontal motor index number
#define INDEX_FR_H		1				// front right horizontal motor index number
#define INDEX_BL_H		2				// back left horizontal motor index number
#define INDEX_BR_H		3				// back right horizontal motor index number
#define INDEX_FL_V		4				// front left vertical motor index number
#define INDEX_FR_V		5				// front right vertical motor index number
#define INDEX_BL_V		6				// back left vertical motor index number
#define INDEX_BR_V		7				// back right vertical motor index number

// temperature sensor
#define ONE_WIRE_BUS  2					// temperature sensor one wire bus pin number
