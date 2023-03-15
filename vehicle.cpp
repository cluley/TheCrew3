#include "vehicle.h"

//void Vehicle::operator=(Vehicle& other) {
//	this->name = other.name;
//	this->result = other.result;
//}

std::ostream& operator<<(std::ostream& stream, Vehicle& vehicle) {
	stream << vehicle.name << ". Время: " << vehicle.result;

	return stream;
}