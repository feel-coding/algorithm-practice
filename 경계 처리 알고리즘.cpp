#include <iostream>
using namespace std;

int main() {
	int n, m;
	int arr[105][105];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int row, col, d, r;
	cin >> row >> col >> d >> r;
	int dr[4] = { 0, 0, 1, -1 };
	int dc[4] = { 1, -1, 0, 0 };
	for (int i = 0; i < r; i++) {
		int nr = row + dr[d];
		int nc = col + dc[d];
		if (!(nr >= 0 && nr < n && nc >= 0 && nc < m)) break;
		row = nr;
		col = nc;
	}
	cout << arr[row][col];
	return 0;
}
