#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;


int main() {
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> maze(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}
	vector<vector<int>> candy(n, vector<int>(m));
	candy[0][0] = maze[0][0];
	for (int i = 1; i < m; i++) {
		candy[0][i] = candy[0][i - 1] + maze[0][i];
	}
	for (int i = 1; i < n; i++) {
		candy[i][0] = candy[i - 1][0] + maze[i][0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			candy[i][j] = max(candy[i - 1][j], candy[i][j - 1]) + maze[i][j];
		}
	}
	cout << candy[n - 1][m - 1];
	return 0;
}