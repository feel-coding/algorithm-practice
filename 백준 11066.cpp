#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//https://www.acmicpc.net/problem/11066
int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		int n;
		cin >> n;
		vector<int> v(n + 1);
		vector<int> sum(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			if (i == 0) {
				sum[i] = v[i];
			}
			else {
				sum[i] = sum[i - 1] + v[i];
			}
		}
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		for (int gap = 1; gap < n; gap++) {
			for (int start = 1; start + gap <= n; start++) {
				int end = start + gap;
				dp[start][end] = INT_MAX;
				for (int mid = start; mid < end; mid++) {
					//cout << dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1] << endl;
					if (dp[start][end] > dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]) {
						//cout << "원래 dp[" << start << "][" << end << "] = " << dp[start][end] << endl;
						dp[start][end] = dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1];
						//cout << "dp[" <<start << "][" << end << "] = dp[" << start << "][" << mid << "] (" << dp[start][mid] << ") + dp[" << mid + 1 << "][" << end << "] (" << dp[mid + 1][end] << ") + sum[" << end << "]" << "(" << sum[end] <<  ") - sum[" << start - 1 << "] ("  << sum[start - 1] << ") = " << dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1] << endl;
					}
				}
			}
			/*for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					cout << dp[j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
		}
		cout << dp[1][n] << '\n';
	}
	return 0;
}
