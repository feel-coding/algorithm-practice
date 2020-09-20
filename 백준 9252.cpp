#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
	for (int i = 0; i <= s1.size(); i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= s2.size(); i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[s1.size()][s2.size()] << endl;
	string result = "";
	int nowRow = s1.size();
	int nowCol = s2.size();
	while (true) {
		if (nowRow == 0 || nowCol == 0) break;
		if (dp[nowRow][nowCol] != dp[nowRow - 1][nowCol] && dp[nowRow][nowCol] != dp[nowRow][nowCol - 1]) {
			result += s1[nowRow - 1];
			nowRow--;
			nowCol--;
		}
		else if (dp[nowRow][nowCol] == dp[nowRow - 1][nowCol]) {
			nowRow--;
		}
		else nowCol--;
	}
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];
	return 0;
}