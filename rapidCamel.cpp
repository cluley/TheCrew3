#include "rapidCamel.h"

RapidCamel::RapidCamel() : Vehicle() {
	name = "Верблюд-быстроход";
	speed = 40.0;
	moveTime = 10;
}

void RapidCamel::racing(int distance) {
	result = distance / double(speed);
	int stops = result / moveTime;
	double stopsTime;

	if (stops == 1 && (int(result) % moveTime) == 0) { 
		stopsTime = 0; 
	}
	else if (stops == 1) {
		stopsTime = 5;
	}
	else if (stops == 2 && (int(result) % moveTime) == 0) { 
		stopsTime = 5; 
	}
	else if (stops == 2) {
		stopsTime = 11.5;
	}
	else if (stops > 2 && (int(result) % moveTime) == 0) { 
		stopsTime = 11.5; 
	}
	else if (stops > 2) {
		stopsTime = 11.5 + ((stops - 2) * 8);
	}
	else { stopsTime = 0; }

	result += stopsTime;
}