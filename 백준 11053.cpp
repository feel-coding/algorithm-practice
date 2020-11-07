#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>	v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int maxLength = 0;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i] && dp[j] > maxLength) {
				maxLength = dp[j];
			}
		}
		dp[i] = maxLength + 1;
	}
	int maxDp = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > maxDp) maxDp = dp[i];
	}
	cout << maxDp;
	return 0;
}