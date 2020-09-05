#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int dr[] = { 0, 0, -1, 1 };
int dc[] = { 1, -1, 0, 0 };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	pair<int, int> waterLocation;
	pair<int, int> sLocation;
	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == '*')
				waterLocation = make_pair(i, j);
			if (v[i][j] == 'S')
				sLocation = make_pair(i, j);
		}
	}

	int minLength = -1;
	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(sLocation.first, sLocation.second, 0, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int cnt = 1;
	bool arrivedFlag = false;
	while (!q.empty()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == '*') {
					for (int k = 0; k < 4; k++) {
						int row = i + dr[k];
						int col = j + dc[k];
						if (row >= n || col >= m || row < 0 || col < 0 || v[row][col] != '.')
							continue;
						v[row][col] = ',';
					}
				}
			}
		}
		while (!q.empty()) {
			tuple<int, int, int, int> cur = q.front();
			if (get<3>(cur) != cnt - 1)
				break;
			q.pop();
			if (v[get<0>(cur)][get<1>(cur)] == 'D') {
				minLength = get<2>(cur);
				break;
			}
			if (!visited[get<0>(cur)][get<1>(cur)]) {
				visited[get<0>(cur)][get<1>(cur)] = true;
				for (int i = 0; i < 4; i++) {
					int row = get<0>(cur) + dr[i];
					int col = get<1>(cur) + dc[i];
					if (row >= n || col >= m || row < 0 || col < 0 || !(v[row][col] == '.' || v[row][col] == 'D'))
						continue;
					if (v[row][col] == 'D') {
						arrivedFlag = true;
						minLength = get<2>(cur) + 1;
						break;
					}
					q.push(make_tuple(row, col, get<2>(cur) + 1, cnt));
				}
			}
			if (arrivedFlag)
				break;
		}
		if (arrivedFlag)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == ',') {
					v[i][j] = '*';
				}
			}
		}
		cnt++;
	}
	if (minLength == -1)
		cout << "KAKTUS";
	else
		cout << minLength;
	return 0;
}