#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1005][1005];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < 1005; i++) {
		dp[0][i] = i;
		dp[i][0] = i;
	}
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
		}
	}
	cout << dp[s1.size()][s2.size()];
	return 0;
}