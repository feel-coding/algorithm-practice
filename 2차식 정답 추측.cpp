#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a;
	cin >> a;
	long long start = 0;
	long long end = sqrt(a) + 1;
	long long mid;
	while (start + 1 < end) {
		mid = (start + end) / 2;
		if (mid * mid + mid <= a) start = mid;
		else end = mid;
	}
	cout << start;
	return 0;
}
