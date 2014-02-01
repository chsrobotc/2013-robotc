// Constants for the autonomous

#define DEFAULT_TIMEOUT 100

#define MOUNT_MAGNITUDE 50
#define MOUNT_DELTA 1000

#define TURN_MAGNITUDE 50
#define TURN_DELTA 1000

#define APPROACH_MAGNITUDE 50
#define APPROACH_DELTA 500

#define SWING_MAGNITUDE 50
#define SWING_DELTA 1000

// the function for it
#include "../motors/SetMotor.fn"

void go(int magright, int magleft, int wait)
{
	setMotor(left, magleft);
	setMotor(right, magright);
	wait1Msec(wait);
	setMotor(left, 0);
	setMotor(right, 0);
}

void wt()
{
	wait1Msec(DEFAULT_TIMEOUT);
}

void lft(int mag, int wait)
{
	setMotor(liftA, mag);
	setMotor(liftB, mag)
	wait1Msec(wait);
	setMotor(liftA, 0);
	setMotor(liftB, 0);
}

void aut()
{
	go(MOUNT_MAGNITUDE, MOUNT_MAGNITUDE, MOUNT_DELTA);
	wt();
	go(TURN_MAGNITUDE, -TURN_MAGNITUDE, TURN_DELTA);
	wt();
	go(APPROACH_MAGNITUDE, APPROACH_MAGNITUDE, APPROACH_DELTA);
	wt();
	lft(SWING_MAGNITUDE, SWING_DELTA);
	wt():
	lft(-SWING_MAGNITUDE, SWING_DELTA);
	
}
