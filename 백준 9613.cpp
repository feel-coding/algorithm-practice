#include <iostream>
using namespace std;

int arr[105];

int main() {
	int testCase, n;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int a = arr[i];
				int b = arr[j];
				int c, gcd;
				while (true) {
					c = a % b;
					if (c == 0) {
						gcd = b;
						break;
					}
					a = b;
					b = c;
				}
				sum += gcd;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}