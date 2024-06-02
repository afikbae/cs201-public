#include <iostream>
#include <ctime>
#include <cmath>
#include "MergeSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "ArrayGeneration.h"
#include "SortTest.h"

#include <iostream>
#include <fstream>

using namespace std;

void bubbleSortTests();
void quickSortTests();
void mergeSortTests();

template<typename T>
void printArray(T* arr, int size);
template<typename T>
void printResults(T* arr, int size, int* sizes);

const int numberOfArrays = 10;
const int numberOfExperiments = 10;
int sizes[numberOfArrays] = {   int(pow(2,3)),
				int(pow(2,4)),
				int(pow(2,5)),
				int(pow(2,6)),
				int(pow(2,7)),
				int(pow(2,8)),
				int(pow(2,9)),
				int(pow(2,10)),
				int(pow(2,11)),
				int(pow(2,12))};

int main (int argc, char *argv[]) {

	bubbleSortTests();
	quickSortTests();
	mergeSortTests();
	return 0;
}

void quickSortTests() {
	double* testResults;

	testResults = sortTest(quickSort, generateRandomArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Quick Sort - Random Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(quickSort, generateSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Quick Sort - Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(quickSort, generateReverseSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Quick Sort - Reverse Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(quickSort, generateAlmostSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Quick Sort - Almost Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;
}

void mergeSortTests() {
	double* testResults;

	testResults = sortTest(mergeSort, generateRandomArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Merge Sort - Random Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(mergeSort, generateSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Merge Sort - Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(mergeSort, generateReverseSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Merge Sort - Reverse Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(mergeSort, generateAlmostSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Merge Sort - Almost Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;
}

void bubbleSortTests() {
	double* testResults;

	testResults = sortTest(bubbleSort, generateRandomArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Bubble Sort - Random Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(bubbleSort, generateSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Bubble Sort - Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(bubbleSort, generateReverseSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Bubble Sort - Reverse Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;

	testResults = sortTest(bubbleSort, generateAlmostSortedArray, sizes, numberOfArrays, numberOfExperiments);
	cout << "Bubble Sort - Almost Sorted Arrray" << endl;
	printResults(testResults, numberOfArrays, sizes);
	delete[] testResults;
}

template<typename T>
void printResults(T* arr, int size, int* sizes) {
	for (int i = 0; i < size; i++) {
		cout << "Size : " << sizes[i] << " - Time Elapsed : " << arr[i] << '\n';
	}
	cout << endl;
}
template<typename T>
void printArray(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
