#pragma once
#include "vehicle.h"

class RapidCamel : public Vehicle {
public:
	RapidCamel();
	void racing(int distance) override;
private:
	int moveTime = 0;
};