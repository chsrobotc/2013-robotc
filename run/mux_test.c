#pragma config(Sensor, S1,     HTSMUX,         sensorI2CCustom)

#include "../drivers/Mux.h"
#include "../drivers/GetSensor.fn"

task main()
{
	while(true) {
nxtDisplayString(1, "~%f~", getSensor(ir));
}
}
