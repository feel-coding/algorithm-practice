#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int arr[305][305];
int temp[305][305];
bool visited[305][305];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int n, m;
int year = 0;

int melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = 0;
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (arr[nr][nc] == 0) cnt++;
			}
			temp[i][j] = cnt;
		}
	}
	int totalIce = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (temp[i][j] > 0) {
				arr[i][j] -= min(arr[i][j], temp[i][j]);
			}
			if (arr[i][j] > 0) totalIce++;
		}
	}
	return totalIce;
}

bool isOne() {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (arr[i][j] > 0) {
				flag = true;
				stack<pair<int, int>> s;
				s.push(make_pair(i, j));
				while (!s.empty()) {
					pair<int, int> cur = s.top();
					s.pop();
					if (!visited[cur.first][cur.second]) {
						visited[cur.first][cur.second] = true;
						for (int d = 0; d < 4; d++) {
							int nr = cur.first + dr[d];
							int nc = cur.second + dc[d];
							if (arr[nr][nc] > 0) {
								s.push(make_pair(nr, nc));
							}
						}
					}
				}
				break;
			}
		}
		if (flag) break;
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (arr[i][j] > 0 && !visited[i][j]) return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (true) {
		year++;
		int cnt = melt();
		if (cnt == 0) {
			cout << 0;
			break;
		}
		if (!isOne()) {
			cout << year;
			break;
		}
	}
	return 0;
}