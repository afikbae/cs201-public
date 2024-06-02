#include <ctime>
#include "ArrayGeneration.h"

template<typename T>
void deleteDoubleArr(T** arr, int size);

double* sortTest(void (*sortFunction)(int*&,int), int** arrays, int* sizes, int numberOfArrays) {
	double* results = new double[numberOfArrays];
	int resultIndex = 0;
	double total_time = 0.0;
	clock_t c_start;
	clock_t c_end;
	double duration;
	for (int i = 0; i < numberOfArrays; i++) {
		c_start = clock();
		sortFunction(arrays[i], sizes[i]);
		c_end = clock();
		duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
		results[resultIndex++] = duration;
	}
	return results;
}

double* sortTest(void (*sortFunction)(int*&,int), int* (*arrayGenerationFunction)(int size), int* sizes, int numberOfArrays, int numberOfExperiments) {
	int** arrays = nullptr;
	double * test_times = new double[numberOfArrays];
	for (int i = 0; i < numberOfArrays; i++) {
		test_times[i] = 0;
	}
	for (int i = 0; i < numberOfExperiments; i++) {
		arrays = generate_arrays_with_given_function(arrayGenerationFunction, sizes, numberOfArrays);
		double* test_results = sortTest(sortFunction, arrays, sizes, numberOfArrays);
		for (int j = 0; j < numberOfArrays; j++) {
			test_times[j] += test_results[j];
		}
		delete[] test_results;
		deleteDoubleArr(arrays, numberOfArrays);
	}

	for (int i = 0; i < numberOfArrays; i++) {
		test_times[i] /= numberOfExperiments;
	}
	return test_times;
}

template<typename T>
void deleteDoubleArr(T** arr, int size) {
	for (int i = 0; i < size; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
