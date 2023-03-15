#pragma once
#include "vehicle.h"

class MagicCarpet : public Vehicle {
public:
	MagicCarpet();
	void racing(int distance) override;
private:
	float redCoef = 0;
};