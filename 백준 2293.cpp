#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	coin = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	vector<int> dp(k + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i]) {
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
	}
	cout << dp[k];
	return 0;
}