#ifndef SORTTEST_H
#define SORTTEST_H
double* sortTest(void (*sortFunction)(int*&, int), int* (*arrayGenerationFunction)(int size), int* sizes, int numberofarrays, int numberofexperiments);
#endif
