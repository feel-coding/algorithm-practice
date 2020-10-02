#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin.begin(), coin.end());
	vector<vector<int>> dp(n, vector<int>(k + 1, 100001));
	for (int i = 1; i <= k; i++) {
		if (i % coin[0] == 0) {
			dp[0][i] = i / coin[0];
		}//최솟값 찾을 때 0을 찾지 않도록 주의하기
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < coin[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else if (j == coin[i]) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - coin[i]] + 1);
				
			}
		}
	}
	if (dp[n - 1][k] != 100001) cout << dp[n - 1][k];
	else cout << -1;
	return 0;
}