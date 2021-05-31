#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr(105, vector<int>(105, -1));
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int main() {
	int n, m, question, d, r;
	int row = 1;
	int col = 1;
	cin >> n >> m >> question;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int q = 0; q < question; q++) {
		cin >> d >> r;
		for (int i = 0; i < r; i++) {
			int nr = row + dr[d];
			int nc = col + dc[d];
			if (arr[nr][nc] == -1) break;
			row = nr;
			col = nc;
		}
		cout << arr[row][col] << '\n';
	}
	return 0;
}
