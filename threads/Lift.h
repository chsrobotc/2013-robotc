#pragma once
/*
 * Lift.h ~ task lift()
 * Alex Jones for team 5105 Buffalo Wings
 *
 * Description: 	A thread that uses the second controller to modify lift values
 *
 * Takes:			- don't know if threads can pass paramaters
 *
 * Returns:			- nothing, its a thread
 *
 * Uses: 			controlling the robots lifts during teleop
 *
 * Dependancies:	motor/SetMotor.fn | controller/All.h
 *
 * ~licensed under the MIT license included in this repositiory
*/

#include "../motors/SetMotor.fn"
#include "../controller/All.h"

task lift()
{
	//initialize the topple servo to make sure we don't kill everyone
	int catchval = 0;
	int toppleval = 127;
	while(true)
	{
		initController();
		motor[topple] = toppleval;
		if(checkButton(A_BUTTON, 2)
		{
			toppleval++;
		}
		else
		{
			toppleval = 127;
		}
		
		motor[mainlift] = scaleJoystick(getJoystick(2, 1, 'y'), LINNEAR);
		servo[sublift] = scaleJoystick(getJoystick(2, 2, 'y'), LINNEAR);
		
		if(checkButton(R_BUMPER))
		{
			motor[brush] = 100;
		}
		else if(chechButton(L_BUMPER))
		{
			motor[brush] = -100;
		}
		else motor[brush] = 0;
		
		if(checkButton(R_TRIGGER))
		{
			motor[grapple] = 100;
		}
		else if(checkButton(L_TRIGGER))
		{
			motor[grapple] = -100;
		}
		else motor[grapple] = 0;
		
		servo[catch] = catchval;
		
		if(checkButton(Y_BUTTON))
		{
			catchval++;
		}
		if(checkButton(X_BUTTON))
		{
			catchval--;
		}
		
		
		/*
		// for the grabber to the pole in endgame
		if(joy2Btn(01))
		{
			servo[grabber] = 255;
		}

		if(checkButton(3, 2))
		{
			servo[grabber] = 255;
		}
		if(checkButton(2, 2))
		{
			servo[grabber] = 255;
		}
		else
		{
			//setGrabber(0); its a servo, so don't do this
		}

		// to pull ourselves up from the ground
		if(checkButton(R_TRIGGER, 2))
		{
			setRise(100);
		}
		else if(checkButton(L_TRIGGER, 2))
		{
			setRise(-100);
		}
		else
		{
			setRise(0);
		}

		// to activate the flag lift
		if(checkButton(A_BUTTON, 2))
		{
			setFlag(100);
		}
		else if(checkButton(B_BUTTON, 2))
		{
			setFlag(-100);
		}
		else
		{
			setFlag(0);
		}

		// to control the main lift up and down
		setLiftVector(scaleJoystick(getJoystick(2, 1, 'y'), LINNEAR));


		// to control the open and close of the capture mecanism
		setCapture(scaleJoystick(getJoystick(2, 2, 'y'), LINNEAR));
		*/
	}



}
