#include <iostream>
#include <string>
using namespace std;

int dp[1005][1005];

int main() {
	string s;
	cin >> s;
	for (int j = 1; j < s.size(); j++) {
		for (int i = j - 1; i >= 0; i--) {
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
			}
		}
	}
	cout << dp[0][s.size() - 1];
	return 0;
}
