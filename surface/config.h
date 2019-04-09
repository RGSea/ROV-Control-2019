// configuration file for program constants


// debug flags
/*
#define DEBUG_VERTICAL_MOTOR_SPEEDS
#define DEBUG_HORIZONTAL_MOTOR_SPEEDS
#define DEBUG_TRIM_VALUES
#define CALIBRATE_MOTORS
*/


// trim & adjustments (in dev)
#define ALTITUDE_TRIM   		10                            	// maximum altitude trim level as a percentage
#define ROLL_TRIM       		10                            	// maximum roll trim level as a percentage
#define PITCH_TRIM      		10                            	// maximum pitch trim level as a percentage
#define SPEED_LIMIT     		1                             	// software speed limiting factor (0-1)
#define YAWRATE         		10							  	// yaw rate

// control input
#define DEADZONE      			15							  	// deadzone for controller input
#define AXIS_MIN      			-32767							// minimum value read from controller axis
#define AXIS_MAX      			32767							// maximum value read from controller axis
#define ROOT2         			1.4142							// value of root2 for calculation

// serial comms
#define BAUDRATE				115200							// baud rate for serial comms (bits/second)					

// motor index numbers
#define INDEX_FL_H    			1								// index number for front left horizontal motor
#define INDEX_FR_H    			7								// index number for front right horizontal motor
#define INDEX_BL_H    			2								// index number for back left horizontal motor
#define INDEX_BR_H    			5								// index number for back right horizontal motor
#define INDEX_FL_V    			0								// index number for front left vertical motor
#define INDEX_FR_V    			6								// index number for front right vertical motor
#define INDEX_BL_V    			3								// index number for back left vertical motor
#define INDEX_BR_V    			4								// index number for back right vertical motor

// potentiometer pin / index numbers
#define INDEX_PITCH_TRIM      	12								// pitch trim slider pin
#define INDEX_ROLL_TRIM       	13								// roll trim slider pin
#define INDEX_MASTER_POWER    	15								// master power dial pin
#define INDEX_ALTITUDE_TRIM   	14								// altitude trim dial pin

// reverse motors
#define REVERSE_FL_H  			false							// reverse front left horizontal motor
#define REVERSE_FR_H  			true 							// reverse front right horizontal motor
#define REVERSE_BL_H  			true 							// reverse back left horizontal motor
#define REVERSE_BR_H  			false 							// reverse back right horizontal motor
#define REVERSE_FL_V  			false 							// reverse front left vertical motor
#define REVERSE_FR_V  			true 							// reverse front right vertical motor
#define REVERSE_BL_V  			true 							// reverse back left vertical motor
#define REVERSE_BR_V  			true 							// reverse back right vertical motor

// pins
#define ENCODER_PIN_1			2								// encoder pin 1 (must be interrupt capable)
#define ENCODER_PIN_2			3								// encoder pin 2 (must be interrupt capable)
#define SWITCH_PIN    			4   							// encoder switch pin (DDR pin mode needs to be input pullup)













