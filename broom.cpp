#include "broom.h"

Broom::Broom() : Vehicle() {
	name = "Метла";
	speed = 20;
}

void Broom::racing(int distance) {
	redCoef = 0.01 * (100 - (distance / 1000));

	distance *= redCoef;
	result = double(distance) / speed;
}