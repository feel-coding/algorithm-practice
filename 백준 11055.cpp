#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = v[i].first;
	}
	int realMax = v[0].first;
	for (int i = 1; i < n; i++) {
		int maxSum = 0;
		for (int j = 0; j < i; j++) {
			if (v[j].first < v[i].first && v[j].second > maxSum) maxSum = v[j].second;
		}
		v[i].second = v[i].first + maxSum;
		if (v[i].second > realMax) realMax = v[i].second;
	}
	cout << realMax;
	return 0;
}