#include <iostream>
#include <cmath>
using namespace std;
int n, m, k;
int arr[25][25];
int weight[40];

int getProfileNum(int row, int col, int radar) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && abs(i - row) + abs(j - col) == radar) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		int maxProfile = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					for (int r = 1; r <= n + m - 2; r++) {
						weight[r] = getProfileNum(i, j, r);
					}
					for (int r = n + m - 2; r >= 1; r--) {
						int cost = 1;
						int ribbon = 0;
						int people = 0;
						for (int d = r; d >= 1; d--) {
							ribbon += cost++ * weight[d];
							people += weight[d];
						}
						if (ribbon <= k && people > maxProfile) {
							maxProfile = people;
						}
					}
				}
			}
		}
		cout << "#" << t << " " << maxProfile << endl;
	}
	return 0;
}