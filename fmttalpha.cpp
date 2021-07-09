#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	y = y - x;
	x = 0;
	int sum = 0;
	for (int i = 1; ; i++) {
		sum += i;
		if (y <= sum * 2) {
			cout << i * 2;
			break;
		}
		if (y - 2 * sum <= i + 1) {
			cout << i * 2 + 1;
			break;
		}
	}
	return 0;
}
