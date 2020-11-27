#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase, n;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		cin >> n;
		vector<int> v(n);
		int minStore = 100;
		int maxStore = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (v[i] > maxStore)
				maxStore = v[i];
			if (v[i] < minStore)
				minStore = v[i];
		}
		cout << (maxStore - minStore) * 2 << '\n';
	}
	return 0;
}