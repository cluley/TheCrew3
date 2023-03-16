#include "centaur.h"

Centaur::Centaur() : Vehicle() {
	name = "Кентавр";
	speed = 15.0;
	moveTime = 8;
}

void Centaur::racing(int distance) {
	result = distance / double(speed);
	int stops = result / moveTime;
	double stopsTime = stops * 2;

	result += stopsTime;
}