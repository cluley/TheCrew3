#pragma once
#include "vehicle.h"

class BootsAWD : public Vehicle {
public:
	BootsAWD();
	void racing(int distance) override;
private:
	int moveTime = 0;
};