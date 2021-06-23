#include <iostream>
using namespace std;

int dp[105];

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 1000007;
	}
	cout << dp[n];
	return 0;
}
