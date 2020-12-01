//include commands for all .h function files
#include "main.h"
#include "chassis.h"
#include "claw.h"
#include "shoulder.h"
#include "wrist.h"
#include "elbow.h"
#include "homeshoulder.h"
#include "homeelbow.h"
#include "holdelbow.h"
#include "holdshoulder.h"
/* - - - - - - - - - - - - - -  - - - - - - - - - -
					port assigments used in this projet
Motors
	1 - Left Drive Motor
	2 - claw motot
	3 - writs motor
	4 - elbow motor
	5 - shoulder motor
ports 6,7, 8, 9 not used
	10 - Right Drive Motor

Analogue Sensors
	1 - Left line sensor
	2 - Right line sensor
	3 - center line sensor
other ports not used

Digital Sensors
	1 - Ultrasinic out
	2 - Ultrasonic in
	3 - Elbow limit switch
	4 - Shoulder Limit swiitch
	5 - bumper switch
	6 - Elbow Encoder
	7 - Elbow Encoder
	8 - Shoulder Encoder
	9 - Shoulder Encoder
	10
- - - - - - - - - - - - - - - - - - - - - - - - - */


//start of op control function
void operatorControl() {
		 int power, turn;
 //start of only infinate while loop in this project
	int ultrasonicValue = 0 ;
	while (1) {
		printf("I and working \n"); //print to terminal
//- - - - - - - - - - joysticks - - - - - - - - - - - - -
 //drive base control
		   power = joystickGetAnalog(1, 2); // vertical axis on left joystick
		  turn  = joystickGetAnalog(1, 1); // horizontal axis on left joystick
		  chassisSet(power + turn, power - turn);
	// controll claw with CH4 of joystick
clawSet(joystickGetAnalog(1, 4));
//- - - - - - - - - - - buttons controlling joints - - - - - - - -
	// control shoulder motor with button 6U and 6D
if(joystickGetDigital(1, 6, JOY_UP)) {
			shoulderSet(127); // pressing up, so shoulder should go up
			}
else if(joystickGetDigital(1, 6, JOY_DOWN)) {
		    shoulderSet(-127); // pressing down, so shoulder should go down
			}
else {
		holdShoulder(0); // no buttons are pressed, stop the shoulder
		  }
 // control elbow motor with button 5U and 5D
if(joystickGetDigital(1, 5, JOY_UP)) {
		elbowSet(127); // pressing up, so elbow should go up
		  }
else if(joystickGetDigital(1, 5, JOY_DOWN)) {
		elbowSet(-127); // pressing down, so elbow should go down
		  }
else{
		elbowSet(0); // no buttons pressed, stop the elbow
		  }
	// control writs motor with button 7U and 7D
if(joystickGetDigital(1, 7, JOY_UP)) {
			wristSet(127); // pressing up, so elbow should go up
			  }
else if(joystickGetDigital(1, 7, JOY_DOWN)) {
		wristSet(-127); // pressing down, so elbow should go down
			  }
else{
			wristSet(0); // no buttons pressed, stop the elbow
		}
// - - - - - - - buttons that call autonomous functions - - - - -
	// call the homeShoulder function with button 8U
if(joystickGetDigital(1, 8, JOY_UP)) {
	homeShoulder(127);
	}
	// call the homeElbow function with button 8D
if(joystickGetDigital(1, 8, JOY_DOWN)) {
	homeElbow(127);
}
	// call the ultrasonicFollow function with button 8R													  }
	if(joystickGetDigital(1, 8, JOY_RIGHT)) {
ultrasonicValue = ultrasonicGet(untrasonic1)
	}

		delay(20);
}
}
