#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[10][10];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int direction[4][4] = { {0, 1, 2, 3}, {3, 2, 0, 1}, {1, 0, 3, 2}, {2, 3, 1, 0} };
bool faucetDirection[6][4] = { {}, {true, false, false, false}, {true, true, false, false}, {true, false, false, true}, {true, false, true, true}, {true, true, true, true} };
vector<pair<int, int>> faucet;

int main() {
	cin >> n >> m;
	int maxCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				faucet.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < faucet.size(); i++) {
		for (int r = 0; r < 4; r++) {
			int type = arr[faucet[i].first][faucet[i].second];
			for (int d = 0; d < 4; d++) {
				int dir = direction[r][d];
				if (faucetDirection[type][d]) {
					int distance = 1;
					while (true) {
						int nr = faucet[i].first + dr[dir] * distance;
						int nc = faucet[i].second + dc[dir] * distance;
						if (nr < 0 || nc < 0 || nr >= n || nc >= m) break;
						if (arr[nr][nc] == 6) break;
						distance++;
						if (arr[nr][nc] != 0)
							continue;
						else arr[nr][nc] = 8;
					}
				}
			}
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (arr[j][k] == 8) {
						cnt++;
						arr[j][k] = 0;
					}
				}
			}
			if (cnt > maxCnt) maxCnt = cnt;
		}
	}
	cout << maxCnt;
	return 0;
}
