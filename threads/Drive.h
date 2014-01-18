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
//#include "../mecanum/moveDeg.fn"

task drive()
{
	while(true)
	{
		initController();
		if(getJoystick(1, 1, 'y') < 5 && getJoystick(1, 1, 'y') > -5 && getJoystick(1, 1, 'x') < 5 && getJoystick(1, 1, 'x') > -5)
			joystickMove(2, 1, 100, CUBE_SCALE);
		else
		{
			joystickMecanum(1, 1, 100, CUBE_SCALE);
		}
	}
}
