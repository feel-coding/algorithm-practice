#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

string arr[30];
bool visited[30][30];
vector<int> cnt;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int n;

int getVillage(int row, int col) {
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	int houseNum = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (!visited[cur.first][cur.second]) {
			visited[cur.first][cur.second] = true;
			houseNum++;
			for (int i = 0; i < 4; i++) {
				int nr = cur.first + dr[i];
				int nc = cur.second + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
				if (arr[nr][nc] == '1') q.push(make_pair(nr, nc));
			}
		}
	}
	return houseNum;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j] == '1') {
				cnt.push_back(getVillage(i, j));
			}
		}
	}
	sort(cnt.begin(), cnt.end());
	cout << cnt.size() << endl;
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << '\n';
	}
	return 0;
}
