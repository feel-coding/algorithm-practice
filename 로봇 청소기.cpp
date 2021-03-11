#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int arr[105][105];
bool visited[105][105];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
int reverseDirection[4] = { 1, 0, 3, 2 };
vector<pair<int, int>> warp[11];
int nextDirection[6][4] = { {0, 1, 2, 3}, {1, 2, 3, 0}, {2, 0, 3, 1}, {3, 0, 1, 2}, {1, 3, 0, 2}, {1, 0, 3, 2} };

pair<int, int> findExit(int warpNumber, int row, int col) {
	if (warp[warpNumber][0].first == row && warp[warpNumber][0].second == col) {
		return warp[warpNumber][1];
	}
	else {
		return warp[warpNumber][0];
	}
}

int clean(int row, int  col, int direction) {
	int startRow = row;
	int startCol = col;
	int startDirection = direction;

	do {
		if (arr[row][col] == -1) { // 낮은 턱에 빠진 경우
			break;
		}
		else if (arr[row][col] <= 5) {
			if (reverseDirection[direction] != nextDirection[arr[row][col]][direction])
				visited[row][col] = true;
			direction = nextDirection[arr[row][col]][direction];
			row = row + dr[direction];
			col = col + dc[direction];
		}
		else { // 워프. 방향은 그대로이므로 direction 바꿀 필요 없음
			pair<int, int> exit = findExit(arr[row][col], row, col);
			visited[row][col] = true;
			row = exit.first;
			col = exit.second;
			visited[row][col] = true;
			row = row + dr[direction];
			col = col + dc[direction];
		}
	} while ((row != startRow || col != startCol || direction != startDirection));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) {
				cnt++;
				visited[i][j] = false;
			}
		}
	}
	return cnt;
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		for (int i = 0; i <= 10; i++) {
			warp[i] = vector<pair<int, int>>();
		}
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] >= 6) {
					warp[arr[i][j]].push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i <= n + 1; i++) {
			arr[i][0] = 5;
			arr[i][n + 1] = 5;
			arr[0][i] = 5;
			arr[n + 1][i] = 5;
		}
		int maxArea = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] == 0) {
					for (int d = 0; d < 4; d++) {
						int area = clean(i, j, d);
						if (area > maxArea)
							maxArea = area;
					}
				}
			}
		}
		cout << "#" << t + 1 << " " << maxArea << '\n';
	}
	return 0;
}