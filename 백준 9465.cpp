#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <queue>
#include <sstream>
using namespace std;


int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		int n;
		cin >> n;
		vector<vector<int>> score(2, vector<int>(n));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> score[i][j];
			}
		}
		vector<pair<int, int>> dp(n);
		dp[0] = make_pair(score[0][0], score[1][0]);
		if (n > 1) dp[1] = make_pair(dp[0].second + score[0][1], dp[0].first + score[1][1]);
		for (int i = 2; i < n; i++) {
			dp[i].first = max(dp[i - 1].second + score[0][i], dp[i - 2].second + score[0][i]);
			dp[i].second = max(dp[i - 1].first + score[1][i], dp[i - 2].first + score[1][i]);
		}
		cout << max(dp[n - 1].first, dp[n - 1].second) << '\n';
	}
	return 0;
}