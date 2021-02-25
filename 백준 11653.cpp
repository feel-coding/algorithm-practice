#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int divider = 2;
	while (n > 1) {
		if (n % divider == 0) {
			n /= divider;
			cout << divider << '\n';
		}
		else {
			divider++;
		}
	}
	return 0;
}