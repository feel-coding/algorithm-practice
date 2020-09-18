#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(3);
	vector<int> minDp(3);
	vector<int> maxDp(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
		minDp[i] = v[i];
		maxDp[i] = v[i];
	}
	
	for (int i = 1; i < n; i++) {
		cin >> v[0] >> v[1] >> v[2];
		int a1 = minDp[0];
		int b1 = minDp[1];
		int c1 = minDp[2];
		int a2 = maxDp[0];
		int b2 = maxDp[1];
		int c2 = maxDp[2];
		minDp[0] = (min(a1 + v[0], b1 + v[0]));
		minDp[1] = (min(min(a1 + v[1], b1 + v[1]), c1 + v[1]));
		minDp[2] = (min(b1 + v[2], c1 + v[2]));
		maxDp[0] = (max(a2 + v[0], b2 + v[0]));
		maxDp[1] = (max(max(a2 + v[1], b2 + v[1]), c2 + v[1]));
		maxDp[2] = (max(b2 + v[2], c2 + v[2]));
	}
	
	int minSum = min(min(minDp[0], minDp[1]), minDp[2]);
	int maxSum = max(max(maxDp[0], maxDp[1]), maxDp[2]);
	cout << maxSum << " " << minSum;
	return 0;
}