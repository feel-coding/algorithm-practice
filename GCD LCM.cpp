#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int tempA = a;
	int tempB = b;
	int c, gcd;
	while (true) {
		c = tempA % tempB;
		if (c == 0) {
			gcd = tempB;
			break;
		}
		tempA = tempB;
		tempB = c;
	}
	cout << gcd << "\n" << a * b / gcd;
}
