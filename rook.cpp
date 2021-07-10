#include <iostream>
using namespace std;

int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
int board[10][10];
int kingRow;
int kingCol;

int main() {
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				kingRow = i;
				kingCol = j;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		board[i][0] = 3;
		board[i][9] = 3;
		board[0][i] = 3;
		board[9][i] = 3;
	}
	for (int d = 0; d < 4; d++) {
		int row = kingRow;
		int col = kingCol;
		while (true) {
			int nr = row + dr[d];
			int nc = col + dc[d];
			if (board[nr][nc] == 3) break;
			if (board[nr][nc] == 2) {
				cout << 1;
				return 0;
			}
			row = nr;
			col = nc;
		}
	}
	cout << 0;
	return 0;
}
