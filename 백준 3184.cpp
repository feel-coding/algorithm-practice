#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> ground(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
		}
	}
	int sheepCount = 0;
	int wolfCount = 0;
	vector<vector<bool>> visited(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ground[i][j] != '#' && !visited[i][j]) {
				int sheep = 0;
				int wolf = 0;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					if (!visited[cur.first][cur.second]) {
						if (ground[cur.first][cur.second] == 'o') sheep++;
						if (ground[cur.first][cur.second] == 'v') wolf++;
						visited[cur.first][cur.second] = true;
						if (cur.first + 1 < n && !visited[cur.first + 1][cur.second] && ground[cur.first + 1][cur.second] != '#') {
							q.push(make_pair(cur.first + 1, cur.second));
						}
						if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second] && ground[cur.first - 1][cur.second] != '#') {
							q.push(make_pair(cur.first - 1, cur.second));
						}
						if (cur.second + 1 < m && !visited[cur.first][cur.second + 1] && ground[cur.first][cur.second + 1] != '#') {
							q.push(make_pair(cur.first, cur.second + 1));
						}
						if (cur.second - 1 >= 0 && !visited[cur.first][cur.second - 1] && ground[cur.first][cur.second - 1] != '#') {
							q.push(make_pair(cur.first, cur.second - 1));
						}
					}
				}
				if (sheep > wolf) {
					sheepCount += sheep;
				}
				else {
					wolfCount += wolf;
				}
			}
		}
	}
	cout << sheepCount << " " << wolfCount;
	return 0;
}