#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };
int n, m;
vector<vector<char>> v;
int maxNum = 0;
vector<bool> visited(26);

void dfs(int r, int c, int num) {
	if (num> maxNum)
		maxNum = num;
	for (int i = 0; i < 4; i++) {
		int row = r + dr[i];
		int col = c + dc[i];
		if (row >= n || col >= m || row < 0 || col < 0 || visited[v[row][col] - 'A'])
			continue;
		visited[v[row][col] - 'A'] = true;
		dfs(row, col, num + 1);
		visited[v[row][col] - 'A'] = false;
		
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	v = vector<vector<char>>(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	visited[v[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << maxNum;
	return 0;
}