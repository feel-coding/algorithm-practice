#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<tuple<int, int, int>> dp(n);
	dp[0] = make_tuple(0, v[0], v[0]);
	if (n > 1) {
		dp[1] = make_tuple(v[0], v[1], v[0] + v[1]);
	}
	for (int i = 2; i < n; i++) {
		get<0>(dp[i]) = max(get<0>(dp[i - 1]), max(get<1>(dp[i - 1]), get<2>(dp[i - 1])));
		get<1>(dp[i]) = get<0>(dp[i - 1]) + v[i];
		get<2>(dp[i]) = get<1>(dp[i - 1]) + v[i];
	}
	cout << max(get<0>(dp[n - 1]), max(get<1>(dp[n - 1]), get<2>(dp[n - 1])));
	return 0;
}