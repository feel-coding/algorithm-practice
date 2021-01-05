#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		vector<int> temp;
		if (i % 3 == 0) {
			temp.push_back(dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			temp.push_back(dp[i / 2] + 1);
		}
		temp.push_back(dp[i - 1] + 1);
		dp[i] = *min_element(temp.begin(), temp.end());
	}
	cout << dp[n];
	return 0;
}