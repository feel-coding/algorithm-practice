#include <iostream>
using namespace std;

int main() {
	long long gcd;
	long long x, y;
	cin >> x >> y;
	long long a = x;
	long long b = y;
	long long c;
	while (true) {
		c = a % b;
		if (c == 0) {
			gcd = b;
			break;
		}
		a = b;
		b = c;
	}
	cout << gcd * x / gcd * y / gcd;
	return 0;
}
