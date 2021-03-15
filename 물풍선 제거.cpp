#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int arr[15][15];
vector<pair<int, int>> balloonLocation;
int result[20];
bool visited[15][15];
bool used[20];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int needleNum;
int minNeedleNum = 20;
bool foundAnswer = false;

struct location {
	int row;
	int col;
	int distance;
};

void pop(int current) {
	if (foundAnswer) return;
	if (current == needleNum) {
		int tempArr[15][15];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tempArr[i][j] = arr[i][j];
				visited[i][j] = false;
			}
		}
		queue<location> q;
		for (int i = 0; i < current; i++) {
			q.push({ balloonLocation[result[i]].first, balloonLocation[result[i]].second, arr[balloonLocation[result[i]].first][balloonLocation[result[i]].second] });
		}
		while (!q.empty()) {
			location cur = q.front();
			q.pop();
			if (!visited[cur.row][cur.col]) {
				visited[cur.row][cur.col] = true;
				tempArr[cur.row][cur.col] = 0;
				for (int d = 1; d <= cur.distance; d++) {
					for (int i = 0; i < 4; i++) {
						int nr = cur.row + dr[i] * d;
						int nc = cur.col + dc[i] * d;
						if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
						if (arr[nr][nc] > 0) {
							q.push({ nr, nc, arr[nr][nc] });
						}
					}
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tempArr[i][j] != 0) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) foundAnswer = true;
		return;
	}
	for (int i = 0; i < balloonLocation.size(); i++) {
		if (!used[i]) {
			if (current == 0) {
				result[current] = i;
				used[i] = true;
				pop(current + 1);
				used[i] = false;
			}
			else {
				if (result[current - 1] < i) {
					result[current] = i;
					used[i] = true;
					pop(current + 1);
					used[i] = false;
				}
			}
		}
	}
}


int main() {
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		balloonLocation = vector<pair<int, int>>();
		foundAnswer = false;
		minNeedleNum = 20;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				visited[i][j] = false;
				if (arr[i][j] > 0) {
					balloonLocation.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 1; i <= balloonLocation.size(); i++) {
			needleNum = i;
			pop(0);
			if (foundAnswer) break;
		}
		cout << "#" << t << " " << (needleNum - k < 0 ? 0 : needleNum - k) << '\n';
	}
	return 0;
}