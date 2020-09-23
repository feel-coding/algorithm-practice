#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		int n, cost;
		cin >> n;
		vector<int> coin(n);
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}
		cin >> cost;
		vector<vector<int>> dp(n, vector<int>(cost + 1));
		for (int i = 0; i <= cost; i++) {
			if (i % coin[0] == 0)
				dp[0][i] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= cost; j++) {
				for (int c = 0; c <= j; c += coin[i]) {
						dp[i][j] += dp[i - 1][j - c];	
				}
			}
		}
		cout << dp[n - 1][cost] << '\n';
	}
	return 0;
}