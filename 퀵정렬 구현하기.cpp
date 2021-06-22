#include <iostream>
using namespace std;

int arr[100005];
int lessNumber[100005];
int greaterNumber[100005];

void quickSort(int start, int end) {
	if (start >= end) return;
	int pivot = arr[start];
	int lessIndex = 0;
	int greaterIndex = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] < pivot) {
			lessNumber[lessIndex++] = arr[i];
		}
		else {
			greaterNumber[greaterIndex++] = arr[i];
		}
	}
	for (int i = 0; i < lessIndex; i++) {
		arr[start + i] = lessNumber[i];
	}
	arr[start + lessIndex] = pivot;
	for (int i = start + lessIndex + 1; i <= end; i++) {
		arr[i] = greaterNumber[i - start - lessIndex - 1];
	}
	quickSort(start, start + lessIndex - 1);
	quickSort(start + lessIndex + 1, end);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
