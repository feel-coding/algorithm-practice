#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, num;
	vector<bool> v(10, true);
	cin >> n >> m;
	int ans;
	for (int i = 0; i < m; i++) {
		cin >> num;
		v[num] = false;
	}
	int k = 0;
	bool up;
	if (m < 10) {
		while (true) {
			int divider = 1;
			bool answer = true;
			if (n - k > 0) {
				while (true) {
					if ((n - k) / divider == 0) {
						break;
					}
					if (!v[(n - k) / divider % 10]) {
						answer = false;
						break;
					}
					divider *= 10;
				}
				if (answer) {
					ans = k;
					up = false;
					break;
				}
			}
			else if (n - k == 0) {
				if (!v[0]) {
					answer = false;
				}
				if (answer) {
					ans = k;
					up = false;
					break;
				}
			}
			answer = true;
			if (n + k == 0) {
				if (!v[0]) {
					answer = false;
				}
				if (answer) {
					ans = k;
					up = true;
					break;
				}
			}
			divider = 1;
			while (true) {
				if ((n + k) / divider == 0)
					break;
				if (!v[(n + k) / divider % 10]) {
					answer = false;
					break;
				}
				divider *= 10;
			}
			if (answer) {
				ans = k;
				up = true;
				break;
			}
			k++;
		}
	}
	else {
		cout << abs(n - 100);
		return 0;
	}
	cout << min((int)(ans + to_string((up ? n + k : n - k)).size()), abs(n - 100));
	return 0;
}