#include <iostream>
#include <vector>
using namespace std;

int n, m, h, a, b;
vector<vector<int>> v;
int answer = -1;

void combination(int k, int num, vector<vector<bool>> visited, vector<pair<int, int>> result) {
	if (answer != -1) {
		return;
	}
	if (num == k) {
		for (int i = 0; i < k; i++) {
			v[result[i].first][result[i].second] = 1;
		}
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			int now = j;
			for (int i = 0; i < h; i++) {
				if (v[i][now] == 1) {
					now++;
				}
				else if (v[i][now - 1] == 1) {
					now--;
				}
			}
			if (now != j) {
				flag = false;
				break;
			}
		}
		if (flag) {
			answer = k;
		}
		for (int i = 0; i < k; i++) {
			v[result[i].first][result[i].second] = 0;
		}
		return;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 1; j < n; j++) {
			if (!visited[i][j] && v[i][j] == 0) {
				if (num == 0) {
					visited[i][j] = true;
					result[num] = make_pair(i, j);
					combination(k, num + 1, visited, result);
					visited[i][j] = false;
				}
				else {
					if (result[num - 1].first < i && v[i][j - 1] == 0 && v[i][j + 1] == 0) {
						visited[i][j] = true;
						result[num] = make_pair(i, j);
						combination(k, num + 1, visited, result);
						visited[i][j] = false;
					}
					else if (result[num - 1].first == i && result[num - 1].second < j && (j - result[num - 1].second) > 1 && v[i][j - 1] == 0 && v[i][j + 1] == 0) {
						visited[i][j] = true;
						result[num] = make_pair(i, j);
						combination(k, num + 1, visited, result);
						visited[i][j] = false;
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m >> h;
	v = vector<vector<int>>(h, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a - 1][b] = 1;
	}
	int lineCount = 0;
	for (int j = 1; j < n; j++) {
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			if (v[i][j] == 1) {
				cnt++;
			}
		}
		if (cnt % 2 == 1) {
			lineCount++;
		}
	}
	if (lineCount > 3) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i <= 3; i++) {
		combination(i, 0, vector<vector<bool>>(h, vector<bool>(n + 1)), vector<pair<int, int>>(i));
	}
	cout << answer;
	return 0;
}
