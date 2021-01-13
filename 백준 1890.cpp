#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	vector<vector<long long>> answer(n, vector<long long>(n, 0));
	answer[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= i; k++) {
				if (v[i - k][j] == k) {
					answer[i][j] += answer[i - k][j];
				}
			}
			for (int k = 1; k <= j; k++) {
				if (v[i][j - k] == k) {
					answer[i][j] += answer[i][j - k];
				}
			}
		}
	}
	cout << answer[n - 1][n - 1];
	return 0;
}