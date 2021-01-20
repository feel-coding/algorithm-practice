#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, row, col, size;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 9) {
				row = i;
				col = j;
				v[i][j] = 0;
			}
		}
	}
	size = 2;
	int cnt = 0;
	int totalSecond = 0;
	while (true) {
		queue<tuple<int, int, int>> q;
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		q.push(make_tuple(row, col, 0));
		bool flag = false;
		int minDistance = 100000;
		vector<pair<int, int>> temp;
		while (!q.empty()) {
			tuple<int, int, int> cur = q.front();
			q.pop();
			if (v[get<0>(cur)][get<1>(cur)] > 0 && v[get<0>(cur)][get<1>(cur)] < size && get<2>(cur) <= minDistance) {
				minDistance = get<2>(cur);
				temp.push_back(make_pair(get<0>(cur), get<1>(cur)));
			}
			if (!visited[get<0>(cur)][get<1>(cur)] && get<2>(cur) <= minDistance) {
				visited[get<0>(cur)][get<1>(cur)] = true;
				for (int i = 0; i < 4; i++) {
					int r = get<0>(cur) + dx[i];
					int c = get<1>(cur) + dy[i];
					int time = get<2>(cur);
					if (r >= 0 && r < n && c >= 0 && c < n) {
						if (v[r][c] <= size) {
							q.push(make_tuple(r, c, time + 1));
						}
					}
				}
			}
		}
		sort(temp.begin(), temp.end());
		if (temp.size() == 0) {
			break;
		}
		else {
			row = temp[0].first;
			col = temp[0].second;
			totalSecond += minDistance;
			cnt++;
			if (cnt == size) {
				size++;
				cnt = 0;
			}
			v[row][col] = 0;
		}
	}
	cout << totalSecond;
	return 0;
}
