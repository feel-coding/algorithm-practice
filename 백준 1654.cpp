#include <iostream>
using namespace std;

int arr[10005];

int main() {
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	long long start = 1;
	long long end = 2147483648;
	long long mid;
	while (start + 1 < end) {
		mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt >= n) {
			start = mid;
		}
		else end = mid;
	}
	cout << start;
	return 0;
}
