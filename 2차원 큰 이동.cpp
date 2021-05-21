#include <iostream>
using namespace std;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int reverseDirection[4] = { 1, 0, 3, 2 };

int main() {
	int n, m, row, col, d, t;
	cin >> n >> m >> row >> col >> d >> t;
	if (d == 0 || d == 1) {
		t %= (n * 2 - 2);
		while (t > 0) {
			if (row + dr[d] * t < 1) {
				t -= (row - 1);
				row = 1;
				d = reverseDirection[d];
			}
			else if (row + dr[d] * t > n) {
				t -= (n - row);
				row = n;
				d = reverseDirection[d];
			}
			else {
				row += dr[d] * t;
				t = 0;
			}
		}
	}
	else {
		t %= (m * 2 - 2);
		while (t > 0) {
			if (col + dc[d] * t < 1) {
				t -= (col - 1);
				col = 1;
				d = reverseDirection[d];
			}
			else if (col + dc[d] * t > m) {
				t -= (m - col);
				col = m;
				d = reverseDirection[d];
			}
			else {
				col += dc[d] * t;
				t = 0;
			}
		}
	}
	cout << row << " " << col;
	return 0;
}
