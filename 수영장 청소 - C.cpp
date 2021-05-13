#include <iostream>
using namespace std;

int n, m, k, t;
int arr[10][10];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int direction[4][4] = { {0, 1, 2, 3}, {3, 2, 0, 1}, {1, 0, 3, 2}, {2, 3, 1, 0} };
bool faucetDirection[6][4] = { {}, {true, false, false, false}, {true, true, false, false}, {true, false, false, true}, {true, false, true, true}, {true, true, true, true} };

int main() {
	cin >> n >> m >> k >> t;
	int cnt = 0;
	int row, col, type;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cnt++;
				if (cnt == k) {
					row = i;
					col = j;
					type = arr[i][j];
				}
			}
		}
	}
	for (int d = 0; d < 4; d++) {
		int dir = direction[t][d];
		if (faucetDirection[type][d]) {
			int distance = 1;
			while (true) {
				int nr = row + dr[dir] * distance;
				int nc = col + dc[dir] * distance;
				if (nr < 0 || nc < 0 || nr >= n || nc >= m) break;
				if (arr[nr][nc] == 6) break;
				distance++;
				if (arr[nr][nc] != 0)
					continue;
				else arr[nr][nc] = 8;
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 8) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
