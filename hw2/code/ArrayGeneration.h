#ifndef ARRAYGENERATION_H
#define ARRAYGENERATION_H
int* generateRandomArray(int size);
int* generateAlmostSortedArray(int size);
int* generateSortedArray(int size);
int* generateReverseSortedArray(int size);
int** generate_arrays_with_given_function(int* (*arrayGenerationFunction)(int size), int* sizes, int numberOfArrays);
#endif
