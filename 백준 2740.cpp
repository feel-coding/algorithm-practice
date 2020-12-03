#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m;
	vector<vector<int>> v1(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v1[i][j];
		}
	}
	cin >> m >> k;
	vector<vector<int>> v2(m, vector<int>(k));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> v2[i][j];
		}
	}
	vector<vector<int>> result(n, vector<int>(k, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int c = 0; c < m; c++) {
				result[i][j] += v1[i][c] * v2[c][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << result[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}