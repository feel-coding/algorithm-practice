#include <iostream>
#include <queue>
using namespace std;

int arr[105][105][105];
int visited[105][105][105];
int dr[6] = { -1, 1, 0, 0, 0, 0 };
int dc[6] = { 0, 0, -1, 1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };

struct location {
	int height;
	int row;
	int col;
	int days;
};

int main() {
	int m, n, h;
	queue<location> q;
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) {
					q.push({ k, i, j, 0 });
				}
			}
		}
	}
	int maxDays = 0;
	while (!q.empty()) {
		location cur = q.front();
		q.pop();
		if (!visited[cur.height][cur.row][cur.col]) {
			visited[cur.height][cur.row][cur.col] = cur.days;
			for (int i = 0; i < 6; i++) {
				int nh = cur.height + dh[i];
				int nr = cur.row + dr[i];
				int nc = cur.col + dc[i];
				if (nh >= h || nr >= n || nc >= m || nh < 0 || nr < 0 || nc < 0) continue;
				if (arr[nh][nr][nc] == 0) q.push({ nh, nr, nc, cur.days + 1 });
			}
		}
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[k][i][j] == 0 && !visited[k][i][j]) {
					cout << -1;
					return 0;
				}
				if (visited[k][i][j] > maxDays) maxDays = visited[k][i][j];
			}
		}
	}
	cout << maxDays;
	return 0;
}
