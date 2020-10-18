#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<vector<char>> v(n);
	vector<vector<bool>> visited(n);
	for (int i = 0; i < n; i++) {
		v[i] = vector<char>(n);
		visited[i] = vector<bool>(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	int normalCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				normalCount++;
				if (v[i][j] == 'R') {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						if (!visited[cur.first][cur.second]) {
							visited[cur.first][cur.second] = true;
							if (cur.first + 1 < n && !visited[cur.first + 1][cur.second] && v[cur.first + 1][cur.second] == 'R') {
								q.push(make_pair(cur.first + 1, cur.second));
							}
							if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second] && v[cur.first - 1][cur.second] == 'R') {
								q.push(make_pair(cur.first - 1, cur.second));
							}
							if (cur.second + 1 < n && !visited[cur.first][cur.second + 1] && v[cur.first][cur.second + 1] == 'R') {
								q.push(make_pair(cur.first, cur.second + 1));
							}
							if (cur.second - 1 >= 0 && !visited[cur.first][cur.second - 1] && v[cur.first][cur.second - 1] == 'R') {
								q.push(make_pair(cur.first, cur.second - 1));
							}
						}
					}
				}
				else if (v[i][j] == 'G') {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						if (!visited[cur.first][cur.second]) {
							visited[cur.first][cur.second] = true;
							if (cur.first + 1 < n && !visited[cur.first + 1][cur.second] && v[cur.first + 1][cur.second] == 'G') {
								q.push(make_pair(cur.first + 1, cur.second));
							}
							if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second] && v[cur.first - 1][cur.second] == 'G') {
								q.push(make_pair(cur.first - 1, cur.second));
							}
							if (cur.second + 1 < n && !visited[cur.first][cur.second + 1] && v[cur.first][cur.second + 1] == 'G') {
								q.push(make_pair(cur.first, cur.second + 1));
							}
							if (cur.second - 1 >= 0 && !visited[cur.first][cur.second - 1] && v[cur.first][cur.second - 1] == 'G') {
								q.push(make_pair(cur.first, cur.second - 1));
							}
						}
					}
				}
				else if (v[i][j] == 'B') {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						if (!visited[cur.first][cur.second]) {
							visited[cur.first][cur.second] = true;
							if (cur.first + 1 < n && !visited[cur.first + 1][cur.second] && v[cur.first + 1][cur.second] == 'B') {
								q.push(make_pair(cur.first + 1, cur.second));
							}
							if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second] && v[cur.first - 1][cur.second] == 'B') {
								q.push(make_pair(cur.first - 1, cur.second));
							}
							if (cur.second + 1 < n && !visited[cur.first][cur.second + 1] && v[cur.first][cur.second + 1] == 'B') {
								q.push(make_pair(cur.first, cur.second + 1));
							}
							if (cur.second - 1 >= 0 && !visited[cur.first][cur.second - 1] && v[cur.first][cur.second - 1] == 'B') {
								q.push(make_pair(cur.first, cur.second - 1));
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			if (v[i][j] == 'G')
				v[i][j] = 'R';
		}
	}
	int abnormalCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				abnormalCount++;
				if (v[i][j] == 'R') {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						if (!visited[cur.first][cur.second]) {
							visited[cur.first][cur.second] = true;
							if (cur.first + 1 < n && !visited[cur.first + 1][cur.second] && v[cur.first + 1][cur.second] == 'R') {
								q.push(make_pair(cur.first + 1, cur.second));
							}
							if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second] && v[cur.first - 1][cur.second] == 'R') {
								q.push(make_pair(cur.first - 1, cur.second));
							}
							if (cur.second + 1 < n && !visited[cur.first][cur.second + 1] && v[cur.first][cur.second + 1] == 'R') {
								q.push(make_pair(cur.first, cur.second + 1));
							}
							if (cur.second - 1 >= 0 && !visited[cur.first][cur.second - 1] && v[cur.first][cur.second - 1] == 'R') {
								q.push(make_pair(cur.first, cur.second - 1));
							}
						}
					}
				}
				else if (v[i][j] == 'B') {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						if (!visited[cur.first][cur.second]) {
							visited[cur.first][cur.second] = true;
							if (cur.first + 1 < n && !visited[cur.first + 1][cur.second] && v[cur.first + 1][cur.second] == 'B') {
								q.push(make_pair(cur.first + 1, cur.second));
							}
							if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second] && v[cur.first - 1][cur.second] == 'B') {
								q.push(make_pair(cur.first - 1, cur.second));
							}
							if (cur.second + 1 < n && !visited[cur.first][cur.second + 1] && v[cur.first][cur.second + 1] == 'B') {
								q.push(make_pair(cur.first, cur.second + 1));
							}
							if (cur.second - 1 >= 0 && !visited[cur.first][cur.second - 1] && v[cur.first][cur.second - 1] == 'B') {
								q.push(make_pair(cur.first, cur.second - 1));
							}
						}
					}
				}
			}
		}
	}
	cout << normalCount << endl;
	cout << abnormalCount << endl;
	return 0;
}