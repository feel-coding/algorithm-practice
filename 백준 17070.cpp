#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> li(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> li[i][j];
		}
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	int count = 0;
	while (!q.empty()) {
		int row1 = q.front().first.first;
		int col1 = q.front().first.second;
		int row2 = q.front().second.first;
		int col2 = q.front().second.second;
		q.pop();
		if (row2 == n - 1 && col2 == n - 1) {
			count++;
			continue;
		}
		if (row1 == row2) {
			if (col2 + 1 < n && li[row2][col2 + 1] == 0)
				q.push(make_pair(make_pair(row2, col2), make_pair(row2, col2 + 1)));
			if (col2 + 1 < n && row2 + 1 < n && li[row2][col2 + 1] == 0 && li[row2 + 1][col2] == 0 && li[row2 + 1][col2 + 1] == 0)
				q.push(make_pair(make_pair(row2, col2), make_pair(row2 + 1, col2 + 1)));
		}
		else if (col1 == col2) {
			if (row2 + 1 < n && li[row2 + 1][col2] == 0)
				q.push(make_pair(make_pair(row2, col2), make_pair(row2 + 1, col2)));
			if (col2 + 1 < n && row2 + 1 < n && li[row2][col2 + 1] == 0 && li[row2 + 1][col2] == 0 && li[row2 + 1][col2 + 1] == 0)
				q.push(make_pair(make_pair(row2, col2), make_pair(row2 + 1, col2 + 1)));
		}
		else {
			if (col2 + 1 < n && li[row2][col2 + 1] == 0)
				q.push(make_pair(make_pair(row2, col2), make_pair(row2, col2 + 1)));
			if (row2 + 1 < n && li[row2 + 1][col2] == 0)
				q.push(make_pair(make_pair(row2, col2), make_pair(row2 + 1, col2)));
			if (col2 + 1 < n && row2 + 1 < n && li[row2][col2 + 1] == 0 && li[row2 + 1][col2] == 0 && li[row2 + 1][col2 + 1] == 0)
				q.push(make_pair(make_pair(row2, col2), make_pair(row2 + 1, col2 + 1)));
		}
	}
	cout << count << endl;
	return 0;
}