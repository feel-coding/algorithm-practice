#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005];
int dp[1000005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	int maxSum = dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (dp[i] > maxSum) maxSum = dp[i];
	}
	cout << maxSum;
	return 0;
}
