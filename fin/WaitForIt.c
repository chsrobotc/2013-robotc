#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     right	,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     left	,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     liftA	,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     liftB	,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     flag,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//waits 10 seconds before going

#include "CTT.h"
#include "JoystickDriver.c"

task main()
{
	waitForStart();
	wait1Msec(10000);
	aut();
}
