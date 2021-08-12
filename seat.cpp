#include <iostream>
using namespace std;

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int main() {
	int arr[1005][1005] = { 0 };
	int r, c, k;
	int direction = 0;
	cin >> r >> c >> k;
	for (int i = 0; i <= r + 1; i++) {
		arr[i][0] = -1;
		arr[i][c + 1] = -1;
	}
	for (int i = 0; i <= c + 1; i++) {
		arr[0][i] = -1;
		arr[r + 1][i] = -1;
	}
	int row = 1;
	int col = 1;
	int tempRow, tempCol;
	int cnt = 1;
	arr[1][1] = 1;
	if (k == 1) {
		cout << 1 << " " << 1;
		return 0;
	}
	if (k > r * c) {
		cout << 0;
		return 0;
	}
	while (true) {
		tempRow = row + dr[direction];
		tempCol = col + dc[direction];
		if (arr[tempRow][tempCol] != 0) {
			direction = (direction + 1) % 4;
			continue;
		}
		row = tempRow;
		col = tempCol;
		arr[row][col] = ++cnt;
		if (cnt == k) {
			cout << row << " " << col;
			return 0;
		}
	}
	return 0;
}
