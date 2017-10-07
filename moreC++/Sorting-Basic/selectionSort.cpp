

void selectionSort(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		int minIndex = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}