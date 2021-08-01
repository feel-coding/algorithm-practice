#include <iostream>
using namespace std;

int main() {
	long long n, m;
	static int arr[1000005];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long start = 0;
	long long end = 1000000000;
	long long mid;
	while (start + 1 < end) {
		mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid <= arr[i])
				sum += (arr[i] - mid);
		}
		if (sum >= m) start = mid;
		else end = mid;
	}
	cout << start;
	return 0;
}
