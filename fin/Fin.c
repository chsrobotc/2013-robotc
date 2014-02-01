//config stuffs


#include "../fin/Fin.h"

bool DEBUG = false;

task main()
{
	if(!DEBUG)
	{
		startTask(drive);
		startTask(lift);
	}
	else
	{
		// do any kind of testing here

	}
	
	while(true) {};
}

task drive()
{
	while(true)
	{
		manageMove();
	}
}

task lift()
{
	while(true)
	{
		manageLift();
	}
}
