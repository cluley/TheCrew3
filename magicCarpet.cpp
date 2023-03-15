#include "magicCarpet.h"

MagicCarpet::MagicCarpet() : Vehicle() {
	name = "Ковер-самолёт";
	speed = 10;
}

void MagicCarpet::racing(int distance) {
	if (distance >= 1000 && distance < 5000) { redCoef = 0.97; }
	else if (distance > 5000 && distance < 10000) { redCoef = 0.9; }
	else if (distance >= 10000) { redCoef = 0.95; }
	else { redCoef = 1; }
	
	distance *= redCoef;
	result = double(distance) / speed;
}