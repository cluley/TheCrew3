#include "bootsAWD.h"

BootsAWD::BootsAWD() : Vehicle() {
	name = "Ботинки-вездеходы";
	speed = 6.0;
	moveTime = 60;
}

void BootsAWD::racing(int distance) {
	result = distance / double(speed);
	int stops = result / moveTime;
	double stopsTime;

	if (stops == 1 && (int(result) % moveTime) == 0) { 
		stopsTime = 0; 
	}
	else if (stops == 1) { 
		stopsTime = 10; 
	}
	else if (stops > 1 && (int(result) % moveTime) == 0) { 
		stopsTime = ((stops - 2) * 5) + 10; 
	}
	else if (stops > 1) {
		stopsTime = ((stops - 1) * 5) + 10; 
	}
	else { stopsTime = 0; }

	result += stopsTime;
}