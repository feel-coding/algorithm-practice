#include <iostream>
#include <cmath>
using namespace std;

int arr[10][10];
int temp[10][10];

int main() {
	int n, m, k, t;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> t;
	for (int s = 0; s < t; s++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int r = i - k; r <= i + k; r++) {
					if (r < 1 || r > n) continue;
					for (int c = j - k; c <= j + k; c++) {
						if (c < 1 || c > m) continue;
						if (r == i && c == j) continue;
						if (abs(i - r) + abs(j - c) <= k) {
							arr[r][c] += temp[i][j];
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
