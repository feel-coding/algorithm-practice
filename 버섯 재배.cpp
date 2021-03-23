#include <iostream>
using namespace std;

int mushroom[55][55];
int height[55][55];
bool hasGrown[55][55];
int n, m;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };

int main() {
	int testCase;
	char seed;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		int cnt = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				hasGrown[i][j] = false;
				height[i][j] = 0;
				cin >> seed;
				if (seed == '0') {
					mushroom[i][j] = 0;
				}
				else {
					mushroom[i][j] = seed - 'A' + 1;
				}
			}
		}
		while (cnt < n * m) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (mushroom[i][j] > 0 && !hasGrown[i][j]) {
						height[i][j]++;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (mushroom[i][j] == 0) {
						for (int d = 0; d < 4; d++) {
							int row = i + dr[d];
							int col = j + dc[d];
							if (mushroom[row][col] == height[row][col] && !hasGrown[row][col] && mushroom[row][col] > mushroom[i][j]) {
								mushroom[i][j] = mushroom[row][col];
							}
						}
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (mushroom[i][j] == height[i][j] && mushroom[i][j] > 0 && !hasGrown[i][j]) {
						hasGrown[i][j] = true;
						cnt++;
					}
				}
			}
		}
		int mushroomCnt[11] = { 0 };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				mushroomCnt[mushroom[i][j]]++;
			}
		}
		cout << "#" << t << " ";
		for (int i = 1; i <= 10; i++) {
			cout << mushroomCnt[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
