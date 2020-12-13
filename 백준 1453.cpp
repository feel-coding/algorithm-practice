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
	int n;
	cin >> n;
	vector<bool> empty(100, true);
	int temp;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (empty[temp - 1]) {
			empty[temp - 1] = false;
		}
		else {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}