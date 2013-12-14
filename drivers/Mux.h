//configure the sensor multiplexer
#include "..\drivers\mux\drivers\hitechnic-sensormux.h"

// Assuming the Sensor MUX is connected to NXT sensor port 4 (S4)
// Assuming the following sensors are connected to the Sensor MUX ports:
// Port 1: compass
// Port 2: gyro
// Port 3: ir
// Port 4: light
#include "..\drivers\mux\drivers\hitechnic-gyro.h"
#include "..\drivers\mux\drivers\hitechnic-compass.h"
#include "..\drivers\mux\drivers\lego-light.h"
#include "..\drivers\mux\drivers\hitechnic-irseeker-v1.h"

#define compass			msensor_S4_1
#define gyro			msensor_S4_2
#define ir				msensor_S4_3
#define light			msensor_S4_4
