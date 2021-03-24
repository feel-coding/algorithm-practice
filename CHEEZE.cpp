#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int arr[105][105];
int visited[105][105];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int n, m;
int cnt = 0;
int hours = 0;
vector<int> meltRow;
vector<int> meltCol;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) cnt++;
		}
	}
	while (cnt > 0) {
		hours++;
		meltRow = vector<int>();
		meltCol = vector<int>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
			}
		}
		stack<pair<int, int>> s;
		s.push(make_pair(0, 0));
		while (!s.empty()) {
			pair<int, int> cur = s.top();
			int row = cur.first;
			int col = cur.second;
			s.pop();
			if (!visited[row][col]) {
				visited[row][col] = true;
				for (int i = 0; i < 4; i++) {
					int nr = row + dr[i];
					int nc = col + dc[i];
					if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
					if (arr[nr][nc] == 1 && !visited[nr][nc]) {
						visited[nr][nc] = true;
						meltRow.push_back(nr);
						meltCol.push_back(nc);
					}
					else if (arr[nr][nc] == 0) s.push(make_pair(nr, nc));
				}
			}
		}
		for (int i = 0; i < meltCol.size(); i++) {
			int row = meltRow[i];
			int col = meltCol[i];
			arr[row][col] = 0;
		}
		cnt -= meltCol.size();
	}
	cout << hours << '\n';
	cout << meltCol.size();
	return 0;
}