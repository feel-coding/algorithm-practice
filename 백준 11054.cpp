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
	vector<int> increasingDp(n);
	vector<int> decreasingDp(n);
	increasingDp[0] = 1;
	for (int i = 1; i < n; i++) {
		int maxLength = 0;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i] && increasingDp[j] > maxLength) {
				maxLength = increasingDp[j];
			}
		}
		increasingDp[i] = maxLength + 1;
	}
	decreasingDp[n - 1] = 1;
	for (int i = n - 1; i >= 0; i--) {
		int maxLength = 0;
		for (int j = n - 1; j > i; j--) {
			if (v[i] > v[j] && decreasingDp[j] > maxLength) {
				maxLength = decreasingDp[j];
			}
		}
		decreasingDp[i] = maxLength + 1;
	}
	vector<int> bitonicDp(n);
	for (int i = 0; i < n; i++) {
		bitonicDp[i] = increasingDp[i] + decreasingDp[i] - 1;
	}
	int maxDp = 0;
	for (int i = 0; i < n; i++) {
		if (bitonicDp[i] > maxDp) maxDp = bitonicDp[i];
	}
	cout << maxDp;
	return 0;
}