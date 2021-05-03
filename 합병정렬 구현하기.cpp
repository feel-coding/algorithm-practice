#include <iostream>
using namespace std;

int arr[100005];
int temp[100005];

void merge(int s1, int e1, int s2, int e2) {
	int p = s1;
	int q = s2;
	int index = 0;
	while (p <= e1 && q <= e2) {
		if (arr[p] < arr[q]) {
			temp[index++] = arr[p++];
		}
		else {
			temp[index++] = arr[q++];
		}
	}
	if (p <= e1) {
		while (p <= e1) {
			temp[index++] = arr[p++];
		}
	}
	else if (q <= e2) {
		while (q <= e2) {
			temp[index++] = arr[q++];
		}
	}
	for (int i = 0; i < index; i++) {
		arr[i + s1] = temp[i];
	}
}

void mergeSort(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	merge(start, mid, mid + 1, end);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
