#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     topRight,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     topLeft,       tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

 /*
 * Test_9-4.c ~
 * Alex Jones for team 5105 Buffalo Wings
 *
 * Description: 	Basic motor testing code
 *
 *
 * Dependancies:	motors/TwoMotors.fn | movement* | controller/InitController.fn | controller/GetJoystick.fn
 *
 * ~licensed under the GNU GPLv3 license included in this repositiory
*/

#include "../movement/TwoMotors.fn"
//#include "../motors/SetMotor.fn"
//#include "../movement/Stop.fn"
//#include "../motors/all.h"
#include "../controller/InitController.fn"
#include "../controller/GetJoystick.fn"

task main()
{
	while(true)
	{
		//initController();
		//setMotor(topLeft, 30);
		getJoystickSettings(joystick);
		//nxtDisplayTextLine(3, "%i",getJoystick(1, 1, 'y'));
		//nxtDisplayTextLine(4, "%i",joystick.joy1_y1);
		twoMotors(getJoystick(1, 2, 'y')/1.28, getJoystick(1, 1, 'y')/1.28);
	}
	return;
}
