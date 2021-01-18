#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, l, r;
	cin >> n >> l >> r;
	vector<vector<int>> v(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	int moveCount = 0;
	while (true) {
		visited = vector<vector<bool>>(n, vector<bool>(n, false));
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					stack<pair<int, int>> stack;
					stack.push(make_pair(i, j));
					int sum = 0;
					vector<pair<int, int>> countries;
					while (!stack.empty()) {
						pair<int, int> cur = stack.top();
						stack.pop();
						int row = cur.first;
						int col = cur.second;
						if (!visited[row][col]) {
							visited[row][col] = true;
							sum += v[row][col];
							countries.push_back(cur);
							if (row + 1 < n && abs(v[row][col] - v[row + 1][col]) >= l && abs(v[row][col] - v[row + 1][col]) <= r) {
								stack.push(make_pair(row + 1, col));
							}
							if (row - 1 >= 0 && abs(v[row][col] - v[row - 1][col]) >= l && abs(v[row][col] - v[row - 1][col]) <= r) {
								stack.push(make_pair(row - 1, col));
							}
							if (col + 1 < n && abs(v[row][col] - v[row][col + 1]) >= l && abs(v[row][col] - v[row][col + 1]) <= r) {
								stack.push(make_pair(row, col + 1));
							}
							if (col - 1 >= 0 && abs(v[row][col] - v[row][col - 1]) >= l && abs(v[row][col] - v[row][col - 1]) <= r) {
								stack.push(make_pair(row, col - 1));
							}
						}
					}
					if (countries.size() > 1) {
						flag = true;
						for (int k = 0; k < countries.size(); k++) {
							int row = countries[k].first;
							int col = countries[k].second;
							v[row][col] = sum / countries.size();
						}
					}
				}
			}
		}
		if (!flag)
			break;
		moveCount++;
	}
	cout << moveCount;
	return 0;
}
