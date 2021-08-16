#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, x, y, r;
	cin >> n >> x >> y >> r;
	x--;
	y--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == x && j == y) {
				cout << "x ";
			}
			else if (abs(i - x) + abs(j - y) <= r) {
				cout << abs(i - x) + abs(j - y) << " ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << '\n';
	}
	return 0;
}
