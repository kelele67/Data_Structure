#include <iostream>
using namespace std;

void insertSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

int main() {
	int a[7] = {1, 3, 52, 2, 5, 235, 51};
	insertSort(a, 7);
	for (int i = 0; i < 7; i++) {
		cout << a[i] << ",";
	}
}