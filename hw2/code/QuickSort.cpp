void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void partition(int*& arr, int left, int right, int& pivotIndex) {
	int pivot = arr[left];
	int unknown = left + 1;
	int s1end = left;

	for (; unknown <= right; unknown++){
		if (arr[unknown] < pivot) {
			swap(arr[unknown], arr[++s1end]);
		}
	}
	pivotIndex = s1end;
	swap(arr[left], arr[pivotIndex]);
}

void quickSort (int *& arr, int left, int right) {
	if (left < right) {
		int pivotIndex;
		partition(arr, left, right, pivotIndex);
		quickSort(arr, left, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, right);
	}
}

void quickSort (int *& arr, int size) {
	quickSort (arr, 0, size-1);

}
