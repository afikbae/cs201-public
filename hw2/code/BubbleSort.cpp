void bubbleSort(int *& arr, int size) {
	bool swapped = true;
	int temp;
	for (int i = 0; i < size && swapped; i++){ 
		swapped = false;
		for (int j = 1; j < size - i; j++) {
			if (arr[j-1] > arr[j]) {
				swapped = true;
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}	
		}
	}
}
