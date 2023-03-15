#pragma once
#include "vehicle.h"

class Centaur : public Vehicle {
public:
	Centaur();
	void virtual racing(int distance) override;
private:
	int moveTime = 0;
};