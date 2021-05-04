#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005][1005];
int dp[1005][1005];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m];
	return 0;
}
