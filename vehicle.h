#pragma once
#include <iostream>

class Vehicle {
public:
	void virtual racing(int distance) {}
	std::string get_name() { return name; }
	double get_result() { return result; }
	auto operator<=>(Vehicle& other) {
		return result <=> other.result;
	}
	//void operator=(Vehicle& other);
	friend std::ostream& operator<<(std::ostream& stream, Vehicle& vehicle);
protected:
	std::string name = "";
	int speed = 0;
	double result = 0;
};