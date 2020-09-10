#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<pair<int, int>> zero;
bool found = false;
int cnt = 0;

void permutation(int num, vector<int> result) {
	if (found)
		return;
	if (num == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		found = true;
		return;
	}
	if (found)
		return;
	int row = zero[num].first;
	int col = zero[num].second;
	for (int i = 1; i <= 9; i++) {
		if (found)
			return;
		bool flag = true;
		for (int j = 0; j < 9; j++) {
			if (board[row][j] == i || board[j][col] == i) {
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;
		for (int r = row / 3 * 3; r < row / 3 * 3 + 3; r++) {
			for (int c = col / 3 * 3; c < col / 3 * 3 + 3; c++) {
				if (board[r][c] == i) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (!flag)
			continue;
		if (flag) {
			result[num] = i;
			board[row][col] = i;
			permutation(num + 1, result);
			board[row][col] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				cnt++;
				zero.push_back(make_pair(i, j));
			}
		}
	}
	permutation(0, vector<int>(cnt));
	return 0;
}