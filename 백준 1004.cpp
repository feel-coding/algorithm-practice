#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	int x1, x2, y1, y2, n, cx, cy, r, cnt;
	for (int t = 0; t < testCase; t++) {
		cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		vector<pair<bool, bool>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> cx >> cy >> r;
			if (pow(cx - x1, 2) + pow(cy - y1, 2) > r * r) {
				v[i].first = false;
			}
			else {
				v[i].first = true;
			}
			if (pow(cx - x2, 2) + pow(cy - y2, 2) > r * r) {
				v[i].second = false;
			}
			else {
				v[i].second = true;
			}
		}
		for (int i = 0; i < n; i++) {
			if (v[i].first != v[i].second) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}