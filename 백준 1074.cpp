#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, r, c;
	cin >> n >> r >> c;
	n = pow(2, n);
	int index = 0;
	while (true) {
		if (n == 1) {
			break;
		}
		if (r < n / 2 && c < n / 2) {
		}
		else if (r < n / 2 && c >= n / 2) {
			c -= n / 2;
			index += pow(n / 2, 2);
		}
		else if (r >= n / 2 && c < n / 2) {
			r -= n / 2;
			index += pow(n / 2, 2) * 2;
		}
		else {
			r -= n / 2;
			c -= n / 2;
			index += pow(n / 2, 2) * 3;
		}
		n /= 2;
	}
	cout << index;
	return 0;
}