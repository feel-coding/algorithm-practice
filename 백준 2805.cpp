#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	static long long arr[1000005];
	int n;
	long long m;
	int maxHeight = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > maxHeight) maxHeight = arr[i];
	}
	int start = 0;
	int end = maxHeight;
	long long mid;
	long long total = 0;
	while (start + 1 < end) {
		total = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			total += max((long long)0, arr[i] - mid);
		}
		if (total == m) {
			cout << mid;
			return 0;
		}
		else if (total < m) {
			end = mid;
		}
		else if (total > m) {
			start = mid;
		}
	}
	cout << start;
	return 0;
}