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
	int n, m, k;
	cin >> n >> m >> k;
	int row, col;
	int cnt = 0;
	int flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cnt == k) {
				row = i;
				col = j;
				flag = true;
				break;
			}
			cnt++;
		}
		if (flag)
			break;
	}
	cout << row << " " << col;
	return 0;
}