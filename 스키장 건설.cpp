#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, k, answer;
int arr[15][15];
int summitHeight = -1;
vector<pair<int, int>> summitLocation;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };

struct location {
	int row;
	int col;
	int currentDirection;
	int changeDirectionCnt;
};

int getResult(int startRow, int startCol, int cutRow, int cutCol, int cuttingHeight) {
	arr[cutRow][cutCol] -= cuttingHeight;
	stack<location> s;
	for (int i = 0; i < 4; i++) {
		int row = startRow + dr[i];
		int col = startCol + dc[i];
		if (row < 0 || col < 0 || row >= n || col >= n) continue;
		if (arr[row][col] < arr[startRow][startCol]) {
			s.push({ row, col, i, 0 });
		}
	}
	int maxCnt = 0;
	while (!s.empty()) {
		location cur = s.top();
		s.pop();
		if (cur.changeDirectionCnt > maxCnt) maxCnt = cur.changeDirectionCnt;
		for (int i = 0; i < 4; i++) {
			int nr = cur.row + dr[i];
			int nc = cur.col + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
			if (arr[nr][nc] < arr[cur.row][cur.col]) {
				if (i == cur.currentDirection) {
					s.push({ nr, nc, i, cur.changeDirectionCnt });
				}
				else {
					s.push({ nr, nc, i, cur.changeDirectionCnt + 1 });
				}
			}
		}
	}
	arr[cutRow][cutCol] += cuttingHeight;
	return maxCnt;
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		cin >> n >> k;
		answer = 0;
		summitLocation = vector<pair<int, int>>();
		summitHeight = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > summitHeight) {
					summitHeight = arr[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == summitHeight) {
					summitLocation.push_back(make_pair(i, j));
				}
			}
		}
		for (int s = 0; s < summitLocation.size(); s++) {
			int row = summitLocation[s].first;
			int col = summitLocation[s].second;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int h = 0; h <= k; h++) {
						if (arr[i][j] != summitHeight && arr[i][j] - h >= 0) {
							int result = getResult(row, col, i, j, h);
							if (result > answer) {
								answer = result;
							}
						}
					}
				}
			}

		}
		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}