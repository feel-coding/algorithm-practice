#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int numerator = a * d + b * c;
	int denominator = b * d;
	int A, B, C;
	A = numerator;
	B = denominator;
	int gcd;
	while (true) {
		C = A % B;
		if (C == 0) {
			gcd = B;
			break;
		}
		A = B;
		B = C;
	}
	cout << numerator / gcd << " " << denominator / gcd;
	return 0;
}
