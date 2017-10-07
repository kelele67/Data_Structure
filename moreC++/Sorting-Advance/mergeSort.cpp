#include <iostream>
using namespace std;

void merge(int arr[], int first, int last, int mid) {
	int i = first, j = mid + 1;
	int s = 0;
	int temp[last-first+1];

	while (i <= mid || j <= last) {
		if (i > mid) {
			while (j <= last) {
				temp[s++] = arr[j++];
			}
		}
		else if (j > last) {
			while (i <= mid) {
				temp[s++] = arr[i++];
			}
		}
		else {
			if (arr[i] < arr[j]) {
				temp[s++] = arr[i++];
			}
			else {
				temp[s++] = arr[j++];
			}
		}
	}
	// save result
	for (int i = 0; i < last-first+1; i++) {
		arr[first+i] = temp[i];
	}
}

void mergeSort(int arr[], int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid+1, last);
		merge(arr, first, last, mid);
	}
}

int main() {
	int a[15] = {5,15,50,25,28,31,40,82,85,10,20,30,35,36,48};
	mergeSort(a, 0, 15);
	for (int i = 0; i < 15; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}