#include <cstdlib>
#include <ctime>

int* generateRandomArray(int size) {
	srand((unsigned int)time(NULL));

	int* new_array = new int[size];
	for (int i = 0; i < size; i++) {
		new_array[i] = rand() % 10000;
	} 
	return new_array;
}

int* generateAlmostSortedArray(int size) {
	srand((unsigned int)time(NULL));

	int *my_array = new int[size];
	for (int i = 0; i < size; i++) {
		my_array[i] = i;

		if (rand() % 10 == 1) {
			my_array[i] = i + size;
		}
	}
	return my_array;
}

int* generateSortedArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i+1;
	}
	return arr;
}

int* generateReverseSortedArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = size - i;
	}
	return arr;
}

int** generate_arrays_with_given_function(int* (*arrayGenerationFunction)(int size), int* sizes, int numberOfArrays) {
	int** arrays = new int*[numberOfArrays];
	for (int i = 0; i < numberOfArrays; i++) {
		arrays[i] = arrayGenerationFunction(sizes[i]);
	}
	return arrays;
}
