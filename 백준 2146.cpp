#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	int number = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && v[i][j] == 1) {
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					v[cur.first][cur.second] = number;
					if (!visited[cur.first][cur.second]) {
						visited[cur.first][cur.second] = true;
						for (int i = 0; i < 4; i++) {
							int row = cur.first + dx[i];
							int col = cur.second + dy[i];
							if (row < n && row >= 0 && col < n && col >= 0 && v[row][col] == 1) {
								q.push(make_pair(row, col));
							}
						}
					}
				}
				number++;
			}
		}
	}
	int minDistance = 100000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] != 0) {
				visited = vector<vector<bool>>(n, vector<bool>(n, false));
				int start = v[i][j];
				queue<tuple<int, int, int>> q;
				q.push(make_tuple(i, j, 0));
				while (!q.empty()) {
					tuple<int, int, int> cur = q.front();
					q.pop();
					if (v[get<0>(cur)][get<1>(cur)] != 0 && v[get<0>(cur)][get<1>(cur)] != start) {
						if (get<2>(cur) - 1 < minDistance)
							minDistance = get<2>(cur) - 1;
						break;
					}
					if (!visited[get<0>(cur)][get<1>(cur)]) {
						visited[get<0>(cur)][get<1>(cur)] = true;
						for (int i = 0; i < 4; i++) {
							int row = get<0>(cur) + dx[i];
							int col = get<1>(cur) + dy[i];
							int distance = get<2>(cur);
							if (row < n && row >= 0 && col < n && col >= 0 && v[row][col] != start) {
								q.push(make_tuple(row, col, distance + 1));
							}
						}
					}
				}
			}
		}
	}
	cout << minDistance;
	return 0;
}
