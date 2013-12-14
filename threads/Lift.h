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

#include "../motor/SetMotor.fn"
#include "../controller/All.h"

task lift()
{
	while(true)
	{
		initController();
		// for the grabber to the pole in endgame
		if(checkButton(R_BUMPER, 2))
		{
			modGrabber(3);
		}
		else if(checkButton(L_BUMPER, 2))
		{
			modGrabber(-3);
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
		if(checkButton(A_BUTTON))
		{
			setFlag(100);
		}
		else if(checkButton(B_BUTTON))
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
	}
	
	
	
}
