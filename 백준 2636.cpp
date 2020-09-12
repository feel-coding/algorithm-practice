#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	int cnt = 0;
	vector<int> countVector;
	cin >> n >> m;
	int temp;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			v[i][j] = temp;
			if (v[i][j] == 1) {
				cnt++;
			}
		}
	}
	countVector.push_back(cnt);
	int hour = 0;
	vector<vector<bool>> visited(n, vector<bool>(m));
	stack<pair<int, int>> s;
	s.push(make_pair(0, 0));
	while (!s.empty()) {
		pair<int, int> cur = s.top();
		s.pop();
		int row = cur.first;
		int col = cur.second;
		if (!visited[row][col]) {
			visited[row][col] = true;
			v[row][col] = -1;
			if (row + 1 < n && v[row + 1][col] == 0) {
				s.push(make_pair(row + 1, col));
			}
			if (row - 1 >= 0 && v[row - 1][col] == 0) {
				s.push(make_pair(row - 1, col));
			}
			if (col + 1 < m && v[row][col + 1] == 0) {
				s.push(make_pair(row, col + 1));
			}
			if (col - 1 >= 0 && v[row][col - 1] == 0) {
				s.push(make_pair(row, col - 1));
			}
		}

	}

	while (true) {
		hour++;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (v[i][j] == 1 && (v[i + 1][j] == -1 || v[i - 1][j] == -1 || v[i][j + 1] == -1 || v[i][j - 1] == -1)) {
					v[i][j] = 2;
				}
			}
		}

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (v[i][j] == 2) {
					v[i][j] = -1;
				}
			}
		}
	
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 1) {
					cnt++;
				}
			}
		}
		if (cnt == 0)
			break;
		countVector.push_back(cnt);
		visited = vector<vector<bool>>(n, vector<bool>(m));
		s.push(make_pair(0, 0));
		while (!s.empty()) {
			pair<int, int> cur = s.top();
			s.pop();
			int row = cur.first;
			int col = cur.second;
			if (!visited[row][col]) {
				visited[row][col] = true;
				v[row][col] = -1;
				if (row + 1 < n && v[row + 1][col] != 1) {
					s.push(make_pair(row + 1, col));
				}
				if (row - 1 >= 0 && v[row - 1][col] != 1) {
					s.push(make_pair(row - 1, col));
				}
				if (col + 1 < m && v[row][col + 1] != 1) {
					s.push(make_pair(row, col + 1));
				}
				if (col - 1 >= 0 && v[row][col - 1] != 1) {
					s.push(make_pair(row, col - 1));
				}
			}

		}

	}
	cout << hour << '\n';
	cout << countVector[countVector.size() - 1];
	return 0;
}