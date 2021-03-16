#include <iostream>
using namespace std;

int arr[100005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int gcd = arr[1] - arr[0];
	for (int i = 2; i < n; i++) {
		int a = arr[i] - arr[i - 1];
		int b = gcd;
		int c;
		while (true) {
			c = a % b;
			if (c == 0) {
				gcd = b;
				break;
			}
			a = b;
			b = c;
		}
	}
	cout << (arr[n - 1] - arr[0]) / gcd + 1 - n;
	return 0;
}