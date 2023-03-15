#pragma once
#include "vehicle.h"

class Broom : public Vehicle {
public:
	Broom();
	void racing(int distance) override;
private:
	float redCoef = 0;
};