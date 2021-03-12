#include <iostream>
#include <queue>
using namespace std;

int arr[1005][1005];
int visited[1005][1005];
int fromS[1005][1005];
int fromE[1005][1005];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
int minDistance = 10000000;

struct location {
	int row;
	int col;
	int distance;
};

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) {
			fromE[i][j] = 10000000;
			fromS[i][j] = 10000000;
		}
	}
	queue<location> q;
	q.push({ n - 1, 0, 0 });
	while (!q.empty()) {
		location cur = q.front();
		q.pop();
		if (!visited[cur.row][cur.col]) {
			fromS[cur.row][cur.col] = cur.distance;
			visited[cur.row][cur.col] = true;
			for (int i = 0; i < 4; i++) {
				int nr = cur.row + dr[i];
				int nc = cur.col + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
				if (arr[nr][nc] == 0) q.push({ nr, nc, cur.distance + 1 });
			}
		}
	}
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) {
			visited[i][j] = false;
		}
	}
	q.push({ 0, m - 1, 0 });
	while (!q.empty()) {
		location cur = q.front();
		q.pop();
		if (!visited[cur.row][cur.col]) {
			fromE[cur.row][cur.col] = cur.distance;
			visited[cur.row][cur.col] = true;
			for (int i = 0; i < 4; i++) {
				int nr = cur.row + dr[i];
				int nc = cur.col + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
				if (arr[nr][nc] == 0) q.push({ nr, nc, cur.distance + 1 });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				if (fromS[i][j] + fromE[i][j] < minDistance) {
					minDistance = fromS[i][j] + fromE[i][j];
				}
			}
			else {
				int fromSMin = 10000000;
				int fromEMin = 10000000;
				for (int d = 0; d < 4; d++) {
					int row = i + dr[d];
					int col = j + dc[d];
					if (row < 0 || col < 0 || row >= n || col > m) continue;
					if (fromS[row][col] < fromSMin) {
						fromSMin = fromS[row][col];
					}
				}
				for (int d = 0; d < 4; d++) {
					int row = i + dr[d];
					int col = j + dc[d];
					if (row < 0 || col < 0 || row >= n || col > m) continue;
					if (fromE[row][col] < fromEMin) {
						fromEMin = fromE[row][col];
					}
				}
				if (fromSMin + fromEMin + 2 < minDistance)
					minDistance = fromSMin + fromEMin + 2;
			}
		}
	}
	cout << minDistance;
	return 0;
}