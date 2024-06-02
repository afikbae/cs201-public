#include <iostream>
void merge(int*& arr, int left, int mid, int right) {
	int* temp = new int[right - left + 1];
	int index1 = left;
	int index2 = mid+1;
	int index = 0;
	while (index1 <= mid && index2 <= right) {
		if (arr[index1] <= arr[index2]) temp[index++] = arr[index1++];
		else temp[index++] = arr[index2++];
	}
	while (index1 <= mid) temp[index++] = arr[index1++];
	while (index2 <= right) temp[index++] = arr[index2++];
	for (index = 0; index < right - left + 1; index++) arr[left + index] = temp[index];
	delete[] temp;
}

void mergeSortHelper (int *& arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSortHelper(arr, left, mid);
		mergeSortHelper(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void mergeSort (int*& arr, int size) {
	mergeSortHelper (arr, 0, size - 1);
}
