#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	int maxDp = 0;
	vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}
			if (dp[i][j] > maxDp)
				maxDp = dp[i][j];
		}
	}
	cout << maxDp;
	return 0;
}