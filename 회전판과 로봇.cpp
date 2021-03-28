#include <iostream>
#include <map>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	map<char, int> direction;
	int arr[510][510];
	int rotation[10];
	int dr[4] = { 0, 0, 1, -1 };
	int dc[4] = { 1, -1, 0, 0 };
	direction['E'] = 0;
	direction['W'] = 1;
	direction['S'] = 2;
	direction['N'] = 3;
	int n, m, c, r;
	for (int t = 0; t < testCase; t++) {
		cin >> m >> n >> c >> r;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
		}
		int score = arr[r][c];
		arr[r][c] = 0;
		for (int i = 0; i <= n + 1; i++) {
			arr[i][0] = -1;
			arr[i][m + 1] = -1;
		}
		for (int j = 0; j <= m + 1; j++) {
			arr[0][j] = -1;
			arr[n + 1][j] = -1;
		}
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> rotation[i];
		}
		int l;
		cin >> l;
		int index = 0;
		for (int i = 0; i < l; i++) {
			char ewsn;
			int rotationDirection, rotationNum;
			cin >> ewsn >> rotationDirection >> rotationNum;
			rotationNum %= k;
			if (rotationDirection == 1) {
				index = (index - rotationNum + k) % k;
			}
			else {
				index = (index + rotationNum) % k;
			}
			int howMuch = rotation[index];
			for (int j = 0; j < howMuch; j++) {
				int nr = r + dr[direction[ewsn]];
				int nc = c + dc[direction[ewsn]];
				if (arr[nr][nc] == -1) break;
				r = nr;
				c = nc;
				score += arr[r][c];
				arr[r][c] = 0;
			}
		}
		cout << "#" << t + 1 << " " << score << " " << c << " " << r << '\n';
	}
	return 0;
}