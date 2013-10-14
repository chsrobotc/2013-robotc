#include "../config/TwoMotors.cfg"

#include "JoystickDriver.c"
#include "../etc/Clamp.fn"
#include "../etc/Scales.var"
#include "../etc/ScaleJoystick.fn"
#include "../movement/TwoMotors.fn"
#include "../controller/GetJoystick.fn"
#include "../controller/InitController.fn"
#include "../teleop/JoystickMove.fn"

task main()
{
	while(true)
	{
		initController();
		joystickMove(1, 10, 100, LINNEAR_SCALE);
		joystickMove(2, 5, 50, SQUARE_SCALE);
	}
}
