#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, second, k;
int arr[105][105];
int temp[105][105];
int purifierRow;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };

void move() {
	/*À­Ä­*/
	int tempValue = arr[1][m];
	for (int j = m; j >= 2; j--) {
		arr[1][j] = arr[1][j - 1];
	}
	for (int i = 1; i < purifierRow - 1; i++) {
		arr[i][1] = arr[i + 1][1];
	}
	for (int j = 1; j < m; j++) {
		arr[purifierRow - 1][j] = arr[purifierRow - 1][j + 1];
	}
	for (int i = purifierRow - 1; i >= 2; i--) {
		arr[i][m] = arr[i - 1][m];
	}
	arr[2][m] = tempValue;
	/*¾Æ·§Ä­*/
	tempValue = arr[purifierRow][1];
	for (int j = 1; j < m; j++) {
		arr[purifierRow][j] = arr[purifierRow][j + 1];
	}
	for (int i = purifierRow; i < n; i++) {
		arr[i][m] = arr[i + 1][m];
	}
	for (int j = m; j >= 2; j--) {
		arr[n][j] = arr[n][j - 1];
	}
	for (int i = n; i >= purifierRow + 1; i--) {
		arr[i][1] = arr[i - 1][1];
	}
	arr[purifierRow + 1][1] = tempValue;
	arr[purifierRow - 1][m] = 0;
	arr[purifierRow][m] = 0;
}

void spread() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int amount = arr[i][j] / (2 * k * k + 2 * k + 1);
			if (amount == 0) continue;
			for (int r = i - 3; r <= i + 3; r++) {
				if (r < 1 || r > n) continue;
				for (int c = j - 3; c <= j + 3; c++) {
					if (c < 1 || c > m) continue;
					if ((r == purifierRow || r == purifierRow - 1) && c == m) continue;
					if (abs(i - r) + abs(j - c) <= k && abs(i - r) + abs(j - c) >= 1) {
						temp[r][c] += amount;
						temp[i][j] -= amount;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		cin >> n >> m >> second >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == -1) {
					purifierRow = i;
				}
			}
		}
		arr[purifierRow - 1][m] = 0;
		arr[purifierRow][m] = 0;
		for (int s = 0; s < second; s++) {
			spread();
			move();
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sum += arr[i][j];
			}
		}
		cout << "#" << t << " " << sum << '\n';
	}
	return 0;
}