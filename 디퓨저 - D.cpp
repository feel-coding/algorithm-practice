#include <iostream>
#include <queue>
using namespace std;

int arr[105][105];
bool visited[105][105];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

struct location {
	int row;
	int col;
	int distance;
};

int main() {
	int n, m, row, col;
	queue<location> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i, j, 0 });
			}
		}
	}
	int maxDistance = 0;
	while (!q.empty()) {
		location cur = q.front();
		q.pop();
		if (!visited[cur.row][cur.col]) {
			if (cur.distance > maxDistance) maxDistance = cur.distance;
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
			if (arr[i][j] == 0 && !visited[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << maxDistance;
	return 0;
}
