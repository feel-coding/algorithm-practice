#include <iostream>
using namespace std;

int main() {
	int n, x, d, t;
	cin >> n >> x >> d >> t;
	t %= (n * 2 - 2);
	while (t > 0) {
		if (d == 0) { // 왼쪽
			if (x - t >= 1) {
				x -= t;
				t = 0;
			}
			else {
				t -= (x - 1);
				x = 1;
				d = 1;
			}
		}
		else { // 오른쪽
			if (x + t <= n) {
				x += t;
				t = 0;
			}
			else {
				t -= (n - x);
				x = n;
				d = 0;
			}
		}
	}
	cout << x << " " << d;
	return 0;
}
