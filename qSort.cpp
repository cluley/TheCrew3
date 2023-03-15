#include "qSort.h"

void qSort(Vehicle** array, int size) {
	int i = 0;
	int j = size - 1;
	Vehicle mid = *array[size / 2];

	do {
		while (*array[i] < mid) i++;
		while (*array[j] > mid) j--;

		if (i <= j) {
			Vehicle temp = *array[i];
			*array[i] = *array[j];
			*array[j] = temp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		qSort(array, j + 1);
	}
	if (i < size) {
		qSort(&array[i], size - i);
	}
}