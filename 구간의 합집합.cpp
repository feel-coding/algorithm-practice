#include <iostream>
using namespace std;

int main() {
	int s[10005];
	int e[10005];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> e[i];
	}
	long long index;
	cin >> index;
	long long start = 1;
	long long end = 1000000001;
	long long mid;
	while (start + 1 < end) {
		mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mid > e[i]) cnt += (e[i] - s[i] + 1);
			else if (mid > s[i]) cnt += (mid - s[i]);
		}
		if (index >= cnt) start = mid;
		else end = mid;
	}
	cout << start;
	return 0;
}
