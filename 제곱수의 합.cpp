#include <iostream>
using namespace std;

int arr[100005];
int dp[100005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int minValue = 100005;
		for (int j = 1; j * j <= i; j++) {
			if (dp[i - j * j] < minValue) minValue = dp[i - j * j];
		}
		dp[i] = minValue + 1;
	}
	cout << dp[n];
	return 0;
}
