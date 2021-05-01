#include <iostream>
#include <queue>
using namespace std;

char arr[55][55];
bool visited[55][55];
bool isSpreaded[500];
bool water[55][55];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
bool arrived = false;
int n, m;

struct location {
	int row;
	int col;
	int distance;
};

void spreadWater() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			water[i][j] = false;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int d = 0; d < 4; d++) {
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (arr[nr][nc] == '*' && arr[i][j] == '.') {
					water[i][j] = true;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (water[i][j]) arr[i][j] = '*';
		}
	}
}

int main() {
	int row, col, destinationRow, destinationCol;
	cin >> n >> m;
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			arr[i][j] = 'X';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				row = i;
				col = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'D') {
				destinationRow = i;
				destinationCol = j;
			}
		}
	}
	queue<location> q;
	isSpreaded[0] = true;
	q.push({ row, col, 0 });
	while (!q.empty()) {
		location cur = q.front();
		q.pop();
		if (!isSpreaded[cur.distance]) {
			spreadWater();
			isSpreaded[cur.distance] = true;
		}
		if (arr[cur.row][cur.col] == '*') continue;
		if (cur.row == destinationRow && cur.col == destinationCol) {
			cout << cur.distance;
			return 0;
		}
		if (!visited[cur.row][cur.col]) {
			visited[cur.row][cur.col] = true;
			for (int i = 0; i < 4; i++) {
				int nr = cur.row + dr[i];
				int nc = cur.col + dc[i];
				if (arr[nr][nc] == '.' || arr[nr][nc] == 'D') {
					q.push({ nr, nc, cur.distance + 1 });
				}
			}
		}
	}
	cout << "KAKTUS";
	return 0;
}
