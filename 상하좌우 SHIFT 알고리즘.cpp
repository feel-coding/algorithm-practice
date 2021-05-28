#include <iostream>
using namespace std;

int main() {
	int arr[105][105];
	int n, m, row, col, d, r;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> row >> col >> d >> r;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	for (int i = 0; i < r; i++) {
		row = row + dx[d];
		col = col + dy[d];
	}
	cout << arr[row][col];
	return 0;
}
