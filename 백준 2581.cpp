#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> v;
	for (int i = m; i <= n; i++) {
		bool flag = false;
		for (int j = 2; j < i / 2 + 1; j++) {
			if (i % j == 0) {
				flag = true;
				break;
			}
		}
		if (i == 1) flag = true;
		if (!flag) v.push_back(i);
	}
	if (v.size() == 0) cout << -1 << endl;
	else {
		int total = 0;
		for (int i = 0; i < v.size(); i++) {
			total += v[i];
		}
		cout << total << endl;
		cout << v[0] << endl;
	}
	return 0;
}