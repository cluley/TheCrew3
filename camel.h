#pragma once
#include "vehicle.h"

class Camel : public Vehicle {
public:
	Camel();
	void racing(int distance) override;
private:
	int moveTime = 0;
};