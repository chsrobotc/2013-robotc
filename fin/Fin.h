#pragma once
 /*
 * Fin.h ~ clutch programming performance
 * Alex Jones for team 5105 Buffalo Wings
 *
 * Description: 	concatination of all needed functions
 *
 * Returns:			Greatness
 *
 * Uses: 			making a robot work at the last second possible
 *
 * Dependancies:	??
 *
 * ~licensed under the MIT license included in this repositiory
*/

int LIFT_JOYSTICK = 1;
int DRIVE_JOYSTICK = 2;
#define SPIN_NAME flag
#include "../controller/Defines.var"
#include "../teleop/JoystickMove.fn"


void setLift(int val)
{
	setMotor(liftA, val);
	setMotor(liftB, val);
}

int OVERRIDE = 1;
int UNDERRIDE = 2;
int BOTH = 3;
void checkOverride()
{
	if(checkButton(Y_BUTTON, 1))
	{
		OVERRIDE = 1;
		UNDERRIDE = 2;
	}
	else if(checkButton(Y_BUTTON, 2))
	{
		OVERRIDE = 2;
		UNDERRIDE = 1;
	}

}

int scaleLift(int user, int top)
{
	return scaleJoystick(getJoystick(LIFT_JOYSTICK, user, 'y'), CUBE_SCALE) * (top*0.01);
}

bool within(int bottom, int top, int val)
{
	if(val > bottom && val > top) return true;
	return false;
}

void manageLift()
{
	if(within(-5, 5, getJoystick(LIFT_JOYSTICK, OVERRIDE, 'x')) && within(-5, 5, getJoystick(LIFT_JOYSTICK, OVERRIDE, 'y')))
	{

		if(checkButton(L_TRIGGER, UNDERRIDE))
		{
			setLift(scaleLift(UNDERRIDE, 50));
		}
		else if(checkButton(R_TRIGGER, UNDERRIDE))
		{
			setLift(scaleLift(UNDERRIDE, 100));
		}
		else
		{
			setLift(scaleLift(UNDERRIDE, 75));
		}
	}
	else
	{
		if(checkButton(L_TRIGGER, OVERRIDE))
		{
			setLift(scaleLift(OVERRIDE, 50));
		}
		else if(checkButton(R_TRIGGER, OVERRIDE))
		{
			setLift(scaleLift(OVERRIDE, 100));
		}
		else
		{
			setLift(scaleLift(OVERRIDE, 75));
		}
	}

	if(checkButton(A_BUTTON, BOTH))
	{
		setMotor(SPIN_NAME, 100);
	}
	else if(checkButton(B_BUTTON, BOTH))
	{
		setMotor(SPIN_NAME, -100);
	}
	else setMotor(SPIN_NAME, 0);
}

void manageMove()
{
	if(within(-5, 5, getJoystick(DRIVE_JOYSTICK, OVERRIDE, 'x')) && within(-5, 5, getJoystick(DRIVE_JOYSTICK, OVERRIDE, 'y')))
	{
		// for the UNDERRIDE controller
		if(checkButton(L_TRIGGER, UNDERRIDE))
		{
			joystickMove(UNDERRIDE, DRIVE_JOYSTICK, 5, 50, CUBE_SCALE);
		}
		else if(checkButton(R_TRIGGER, UNDERRIDE))
		{
			joystickMove(UNDERRIDE, DRIVE_JOYSTICK, 5, 100, CUBE_SCALE);
		}
		else
		{
			joystickMove(UNDERRIDE, DRIVE_JOYSTICK, 5, 75, CUBE_SCALE);
		}
	}
	else
	{
		if(checkButton(L_TRIGGER, OVERRIDE))
		{
			joystickMove(OVERRIDE, DRIVE_JOYSTICK, 5, 50, CUBE_SCALE);
		}
		else if(checkButton(R_TRIGGER, OVERRIDE))
		{
			joystickMove(OVERRIDE, DRIVE_JOYSTICK, 5, 100, CUBE_SCALE);
		}
		else
		{
			joystickMove(OVERRIDE, DRIVE_JOYSTICK, 5, 75, CUBE_SCALE);
		}
	}

	if(checkButton(R_BUMPER, BOTH))
	{
		bFloatDuringInactiveMotorPWM = true;
	}
	else bFloatDuringInactiveMotorPWM = false;



}
