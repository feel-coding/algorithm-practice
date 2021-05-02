#include <iostream>
using namespace std;

int arr[25][25];

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int maxScore = 0;
	int maxCol = 0;
	for (int j = 0; j < m; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 1) {
				break;
			}
			cnt++;
		}
		if (cnt >= 4) {
			arr[cnt - 1][j] = 1;
			arr[cnt - 2][j] = 1;
			arr[cnt - 3][j] = 1;
			arr[cnt - 4][j] = 1;
			int score = 0;
			for (int r = 0; r < n; r++) {
				bool flag = true;
				for (int c = 0; c < m; c++) {
					if (arr[r][c] == 0) {
						flag = false;
						break;
					}
				}
				if (flag) score++;
			}
			arr[cnt - 1][j] = 0;
			arr[cnt - 2][j] = 0;
			arr[cnt - 3][j] = 0;
			arr[cnt - 4][j] = 0;
			if (score > maxScore) {
				maxScore = score;
				maxCol = j + 1;
			}
		}
	}
	cout << maxCol << " " << maxScore;
	return 0;
}
