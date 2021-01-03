#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	int index = 0;
	while (!v.empty()) {
		if (v.size() == n) {
			cout << '<';
		}
		index += (k - 1);
		index %= v.size();
		cout << v[index];
		v.erase(v.begin() + index);
		if (v.empty()) {
			cout << '>';
		}
		else {
			cout << ", ";
		}
	}
	return 0;
}