#include <iostream>
using namespace std;

int dr[8] = { 0, 0, -1, -1, -1, 1, 1, 1 };
int dc[8] = { -1, 1, -1, 0, 1, -1, 0, 1 };
int arr[105][105] = { 0 };

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	if (arr[x][y] == 1) {
		cout << "game over";
		return 0;
	}
	else {
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			int row = x + dr[i];
			int col = y + dc[i];
			if (arr[row][col]) cnt++;
		}
		cout << cnt;
	}
	return 0;
}
