#include <iostream>
using namespace std;

int main() {
	int n, m, k, t, y, x, d, f;
	cin >> n >> m >> k >> t;
	for (int i = 0; i < k; i++) {
		cin >> y >> x >> d >> f;
		if (d == 0) {
			y = y - f * t;
			if (y < 1) y = 1;
		}
		else if (d == 1) {
			y = y + f * t;
			if (y > n) y = n;
		}
		else if (d == 2) {
			x = x - f * t;
			if (x < 1) x = 1;
		}
		else if (d == 3) {
			x = x + f * t;
			if (x > m) x = m;
		}
		cout << y << " " << x << '\n';
	}
	return 0;
}
