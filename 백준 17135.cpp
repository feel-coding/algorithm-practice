#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int n, m, d;
int maxNum = 0;
int dx[4] = { -1, 0, 0 };
int dy[4] = { 0, 1, -1 };

void combination(int num, vector<int> result, vector<bool> visited) {
	if (num == 3) {
		int cnt = 0; // 공격한 적의 명수
		vector<vector<int>> tempV = v;
		for (int r = n; r >= 1; r--) {
			vector<vector<bool>> visited(r, vector<bool>(m, false));
			queue<tuple<int, int, int>> q;
			q.push(make_tuple(r - 1, result[0], 1));
			int distance = d;
			vector<pair<int, int>> temp;
			set<pair<int, int>> answer;
			while (!q.empty()) {
				tuple<int, int, int> cur = q.front();
				q.pop();
				if (tempV[get<0>(cur)][get<1>(cur)] == 1 && get<2>(cur) <= distance) {
					distance = get<2>(cur);
					temp.push_back(make_pair(get<1>(cur), get<0>(cur)));
				}
				if (!visited[get<0>(cur)][get<1>(cur)]) {
					visited[get<0>(cur)][get<1>(cur)] = true;
					for (int i = 0; i < 3; i++) {
						int row = get<0>(cur) + dx[i];
						int col = get<1>(cur) + dy[i];
						if (row >= 0 && col >= 0 && col < m && !visited[row][col] && get<2>(cur) < distance) {
							q.push(make_tuple(row, col, get<2>(cur) + 1));
						}
					}
				}
			}
			sort(temp.begin(), temp.end());
			if (temp.size() > 0) {
				answer.insert(temp[0]);
			}

			visited = vector<vector<bool>>(r, vector<bool>(m, false));
			q = queue<tuple<int, int, int>>();
			q.push(make_tuple(r - 1, result[1], 1));
			distance = d;
			temp.clear();
			while (!q.empty()) {
				tuple<int, int, int> cur = q.front();
				q.pop();
				if (tempV[get<0>(cur)][get<1>(cur)] == 1 && get<2>(cur) <= distance) {
					distance = get<2>(cur);
					temp.push_back(make_pair(get<1>(cur), get<0>(cur)));
				}
				if (!visited[get<0>(cur)][get<1>(cur)]) {
					visited[get<0>(cur)][get<1>(cur)] = true;
					for (int i = 0; i < 3; i++) {
						int row = get<0>(cur) + dx[i];
						int col = get<1>(cur) + dy[i];
						if (row >= 0 && col >= 0 && col < m && !visited[row][col] && get<2>(cur) < distance) {
							q.push(make_tuple(row, col, get<2>(cur) + 1));
						}
					}
				}
			}
			sort(temp.begin(), temp.end());
			if (temp.size() > 0) {
				answer.insert(temp[0]);
			}

			visited = vector<vector<bool>>(r, vector<bool>(m, false));
			q = queue<tuple<int, int, int>>();
			q.push(make_tuple(r - 1, result[2], 1));
			distance = d;
			temp.clear();
			while (!q.empty()) {
				tuple<int, int, int> cur = q.front();
				q.pop();
				if (tempV[get<0>(cur)][get<1>(cur)] == 1 && get<2>(cur) <= distance) {
					distance = get<2>(cur);
					temp.push_back(make_pair(get<1>(cur), get<0>(cur)));
				}
				if (!visited[get<0>(cur)][get<1>(cur)]) {
					visited[get<0>(cur)][get<1>(cur)] = true;
					for (int i = 0; i < 3; i++) {
						int row = get<0>(cur) + dx[i];
						int col = get<1>(cur) + dy[i];
						if (row >= 0 && col >= 0 && col < m && !visited[row][col] && get<2>(cur) < distance) {
							q.push(make_tuple(row, col, get<2>(cur) + 1));
						}
					}
				}
			}
			sort(temp.begin(), temp.end());
			if (temp.size() > 0) {
				answer.insert(temp[0]);
			}

			for (set<pair<int, int>>::iterator iter = answer.begin(); iter != answer.end(); iter++) {
				int row = (*iter).second;
				int col = (*iter).first;
				tempV[row][col] = 0;
				cnt++;
			}
		}
		if (cnt > maxNum) {
			maxNum = cnt;
		}
		return;
	}
	for (int i = 0; i < m; i++) {
		if (num == 0) {
			result[num] = i;
			visited[i] = true;
			combination(num + 1, result, visited);
			visited[i] = false;
		}
		else {
			if (result[num - 1] < i) {
				result[num] = i;
				visited[i] = true;
				combination(num + 1, result, visited);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m >> d;
	v = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	combination(0, vector<int>(3), vector<bool>(m, false));
	cout << maxNum;
	return 0;
}
