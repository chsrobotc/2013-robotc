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

#include "../motors/TwoMotors.fn"
#include "../movement/all.h"
#include "../controller/InitController.fn"
#include "../controller/GetJoystick.fn"

task main()
{
	while(true)
	{
		initController();
		twoMotors(getJoystick(1, 1, 'x'), getJoystick(1, 1, 'y'));
	}
}