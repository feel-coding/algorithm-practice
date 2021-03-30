#include <iostream>
using namespace std;

int main() {
	int arr[55][55];
	int tempArr[55][55] = { 0 };
	int testCase;
	cin >> testCase;
	int n, m, k, a, d, c;
	for (int t = 0; t < testCase; t++) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i <= m + 1; i++) {
			arr[0][i] = -1;
			arr[n + 1][i] = -1;
		}
		for (int r = 0; r < k; r++) {
			cin >> a >> d >> c;
			if (d == 0) { // 시계 방향
				for (int f = a; f <= n; f += a) { // a의 배수 층
					for (int r = 0; r < c; r++) { // 시계방향으로 c칸 움직인다
						int temp = arr[f][m];
						for (int i = m; i >= 2; i--) {
							arr[f][i] = arr[f][i - 1];
						}
						arr[f][1] = temp;
					}
				}
			}
			else { // 반시계방향
				for (int f = a; f <= n; f += a) {
					for (int r = 0; r < c; r++) {
						int temp = arr[f][1];
						for (int i = 1; i <= m - 1; i++) {
							arr[f][i] = arr[f][i + 1];
						}
						arr[f][m] = temp;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					tempArr[i][j] = 0;
				}
			}
			bool hasRemoved = false;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (arr[i][j] != 0) {
						int tempLeft = j - 1;
						int tempRight = j + 1;
						if (tempLeft == 0) tempLeft = m;
						if (tempRight == m + 1) tempRight = 1;
						if (arr[i][j] == arr[i + 1][j] || arr[i][j] == arr[i - 1][j] || arr[i][j] == arr[i][tempRight] || arr[i][j] == arr[i][tempLeft]) {
							tempArr[i][j] = -1;
							hasRemoved = true;
						}
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (tempArr[i][j] == -1) arr[i][j] = 0;
				}
			}
			if (!hasRemoved) {
				int cnt = 0;
				int total = 0;
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						total += arr[i][j];
						if (arr[i][j] != 0) cnt++;
					}
				}
				int average = total / cnt;
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if (arr[i][j] > average) {
							arr[i][j]--;
						}
						else if (arr[i][j] != 0 && arr[i][j] < average) {
							arr[i][j]++;
						}
					}
				}
			}

		}


		int total = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				total += arr[i][j];
			}
		}
		cout << "#" << t + 1 << " " << total << '\n';
	}
	return 0;
}
