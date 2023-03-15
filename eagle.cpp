#include "eagle.h"

Eagle::Eagle() : Vehicle() {
	name = "Орёл";
	speed = 8;
}

void Eagle::racing(int distance) {
	distance *= redCoef;
	result = double(distance) / speed;
}