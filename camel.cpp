#include "camel.h"

Camel::Camel() : Vehicle() {
	name = "Верблюд";
	speed = 10;
	moveTime = 30;
}

void Camel::racing(int distance) {
	result = distance / speed;
	int stops = result / moveTime;
	double stopsTime;

	if (stops == 1 && (int(result) % moveTime) == 0) { 
		stopsTime = 0; 
	}
	else if (stops == 1) { 
		stopsTime = 5; 
	}
	else if (stops > 1 && (int(result) % moveTime) == 0) { 
		stopsTime = ((stops - 2) * 8) + 5; 
	}
	else if (stops > 1) { 
		stopsTime = ((stops - 1) * 8) + 5; 
	}
	else { stopsTime = 0; }

	result += stopsTime;
}