#include <iostream>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long start = 1;
	long long end = n * n + 1;
	long long mid;
	while (start + 1 < end) {
		mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (mid / i > n) {
				cnt += n;
			}
			else if (mid % i == 0) {
				cnt += mid / i - 1;
			}
			else {
				cnt += mid / i;
			}
		}
		if (cnt + 1 <= k) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	cout << start;
	return 0;
}