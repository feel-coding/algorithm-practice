#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <iomanip>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] != 0) {
				cnt++;
			}
		}
	}
	int answer = 0;
	int year = 0;
	int isSplited = false;
	while (true) {
		vector<vector<int>> temp = v;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				int zeroCount = 0;
				if (v[i][j] != 0) {
					for (int k = 0; k < 4; k++) {
						int row = i + dx[k];
						int col = j + dy[k];
						if (v[row][col] == 0) {
							zeroCount++;
						}
					}
					temp[i][j] -= zeroCount;
					if (temp[i][j] < 0)
						temp[i][j] = 0;
				}
			}
		}
		v = temp;
		vector<vector<bool>> visited(n, vector<bool>(m));
		bool out = false;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (v[i][j] != 0) {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						if (!visited[cur.first][cur.second]) {
							visited[cur.first][cur.second] = true;
							for (int i = 0; i < 4; i++) {
								int row = cur.first + dx[i];
								int col = cur.second + dy[i];
								if (v[row][col] != 0) {
									q.push(make_pair(row, col));
								}
							}
						}
					}
					out = true;
					break;
				}
				if (out)
					break;
			}
			if (out)
				break;
		}
		for (int r = 1; r < n - 1; r++) {
			for (int c = 1; c < m - 1; c++) {
				if (v[r][c] != 0 && !visited[r][c]) {
					isSplited = true;
					break;
				}
			}
			if (isSplited)
				break;
		}
		year++;
		if (isSplited)
			break;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] != 0) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (flag) {
			break;
		}
	}
	if (!isSplited) {
		cout << 0;
	}
	else cout << year;
	return 0;
}
