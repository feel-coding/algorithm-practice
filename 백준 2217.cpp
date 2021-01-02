#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	vector<int> v;
	cin >> n;
	int weight;
	for (int i = 0; i < n; i++) {
		cin >> weight;
		v.push_back(weight);
	}
	sort(v.begin(), v.end());
	int maxWeight = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] * (n - i) > maxWeight) {
			maxWeight = v[i] * (n - i);
		}
	}
	cout << maxWeight;
	return 0;
}