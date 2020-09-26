#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<int>> dp;

int dfs(int row, int col) {
	if (dp[row][col] == -1) {
		dp[row][col] = 0;
		if (row + 1 < n && v[row][col] > v[row + 1][col]) {
			dp[row][col] += dfs(row + 1, col);
		}
		if (col + 1 < m && v[row][col] > v[row][col + 1]) {
			dp[row][col] += dfs(row, col + 1);
		}
		if (row - 1 >= 0 && v[row][col] > v[row - 1][col]) {
			dp[row][col] += dfs(row - 1, col);
		}
		if (col - 1 >= 0 && v[row][col] > v[row][col - 1]) {
			dp[row][col] += dfs(row, col - 1);
		}
	}
	return dp[row][col];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	dp = vector<vector<int>>(n, vector<int>(m, -1));
	dp[n - 1][m - 1] = 1;
	cout << dfs(0, 0);
	return 0;
}