#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int maxDistance = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				queue<tuple<int, int, int>> q;
				vector<vector<bool>> visited(n, vector<bool>(m));
				q.push(make_tuple(i, j, 0));
				while (!q.empty()) {
					tuple<int, int, int> cur = q.front();
					q.pop();
					int row = get<0>(cur);
					int col = get<1>(cur);
					if (!visited[row][col]) {
						if (get<2>(cur) > maxDistance)
							maxDistance = get<2>(cur);
						visited[row][col] = true;
						if (row + 1 < n && map[row + 1][col] == 'L' && !visited[row + 1][col]) {
							q.push(make_tuple(row + 1, col, get<2>(cur) + 1));
						}
						if (row - 1 >= 0 && map[row - 1][col] == 'L' && !visited[row - 1][col]) {
							q.push(make_tuple(row - 1, col, get<2>(cur) + 1));
						}
						if (col + 1 < m && map[row][col + 1] == 'L' && !visited[row][col + 1]) {
							q.push(make_tuple(row, col + 1, get<2>(cur) + 1));
						}
						if (col - 1 >= 0 && map[row][col - 1] == 'L' && !visited[row][col - 1]) {
							q.push(make_tuple(row, col - 1, get<2>(cur) + 1));
						}
					}
				}
			}
		}
	}
	cout << maxDistance;
	return 0;
}