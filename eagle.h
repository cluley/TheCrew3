#pragma once
#include "vehicle.h"

class Eagle : public Vehicle {
public:
	Eagle();
	void racing(int distance) override;
private:
	float redCoef = 0.94;
};