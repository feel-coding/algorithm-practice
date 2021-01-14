#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<bool> v(n + 1, true);
	int index = 1;
	int answer = -1;
	while (true) {
		int num;
		for (int i = 2; i <= n; i++) {
			if (v[i]) {
				num = i;
				v[i] = false;
				if (index == k) {
					answer = i;
				}
				index++;
				break;
			}
		}
		if (answer != -1)
			break;
		int a = 2;
		while (a * num <= n) {
			if (v[a * num]) {
				v[a * num] = false;
				if (index == k) {
					answer = a * num;
					break;
				}
				index++;
			}
			a++;
		}
		if (answer != -1)
			break;
	}
	cout << answer;
	return 0;
}
