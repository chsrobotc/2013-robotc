#pragma once
 /*
 * Drive.h ~ task drive()
 * Alex Jones for team 5105 Buffalo Wings
 *
 * Description: 	The thread designated to polling and modifing the
 * 					driving motors during the teleop period.
 *
 * Uses: 			teleop driving proccedures
 *
 * Dependancies:	motors/All.h | controller/? |
 *
 * ~licensed under the MIT license included in this repositiory
*/

#include "../motors/All.h"
#include "../mecanum/moveDeg.fn"

task drive()
{
	while(true)
	{
		initController();
		if(getJoystick(1, 1, 'y') < 5 && getJoystick(1, 1, 'y') > -5 && getJoystick(1, 1, 'x') < 5 && getJoystick(1, 1, 'x') > -5)
			joystickMove(2, 1, 100, CUBE_SCALE);
		else
		{
			// this is when it get complicated

			// I need to find the magnitude and direction of the joystick
			float xval = getJoystick(1, 2, 'x');
			float yval = getJoystick(1, 1, 'y');

			// get the direction by using some trig
			float dir = radiansToDegrees(atan2(yval, xval));

			// get the magnitude with the pythagrean theorem
			float mag = sqrt((xval * xval) + (yval * yval)) / 11;

			moveDeg(mag, dir);
		}
	}
}
