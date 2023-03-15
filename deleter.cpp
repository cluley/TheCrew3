#include "deleter.h"

void deleter(Vehicle**& array) {
	delete[] array;
	array = nullptr;
}