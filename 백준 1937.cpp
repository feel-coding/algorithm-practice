#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> dp;
int n;

int dfs(int i, int j) {
	bool flag = false;
	if (dp[i][j] != 0) return dp[i][j];
	int maximum = 0;
	if (i + 1 < n && v[i][j] < v[i + 1][j]) {
		int temp = 1 + dfs(i + 1, j);
		if (temp > maximum) {
			dp[i][j] = temp;
			maximum = temp;
		}
		flag = true;
	}
	if (i - 1 >= 0 && v[i][j] < v[i - 1][j]) {
		int temp = 1 + dfs(i - 1, j);
		if (temp > maximum) {
			dp[i][j] = temp;
			maximum = temp;
		}
		flag = true;
	}
	if (j + 1 < n && v[i][j] < v[i][j + 1]) {
		int temp = 1 + dfs(i, j + 1);
		if (temp > maximum) {
			dp[i][j] = temp;
			maximum = temp;
		}
		flag = true;
	}
	if (j - 1 >= 0 && v[i][j] < v[i][j - 1]) {
		int temp = 1 + dfs(i, j - 1);
		if (temp > maximum) {
			dp[i][j] = temp;
			maximum = temp;
		}
		flag = true;
	}
	if (!flag) {
		dp[i][j] = 1;
	}
	return dp[i][j];
}

int main() {
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	int maxDp = 0;
	dp = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dfs(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] > maxDp) maxDp = dp[i][j];
		}
	}
	cout << maxDp;
	return 0;
}