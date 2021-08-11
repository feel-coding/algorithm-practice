#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int arr[100005];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int minSum = 2000000001;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		int start = i + 1;
		int end = n - 1;
		int mid;
		while (start + 1 < end) {
			mid = (start + end) / 2;
			if (arr[i] + arr[mid] <= 0) {
				start = mid;
			}
			else {
				end = mid;
			}
		}
		if (min(abs(arr[i] + arr[start]), abs(arr[i] + arr[end])) < minSum) {
			if (min(abs(arr[i] + arr[start]), abs(arr[i] + arr[end])) == abs(arr[i] + arr[start])) {
				minSum = abs(arr[i] + arr[start]);
				a = arr[i];
				b = arr[start];
			}
			else {
				minSum = abs(arr[i] + arr[end]);
				a = arr[i];
				b = arr[end];
			}
		}
	}
	cout << a << " " << b;
	return 0;
}
