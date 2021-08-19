#include <iostream>
using namespace std;

int main() {
	int board[5][5];
	bool visited[5][5] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	int n;
	for (int b = 0; b < 25; b++) {
		cin >> n;
		int r, c;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (board[j][k] == n) {
					r = j;
					c = k;
					break;
				}
			}
		}
		visited[r][c] = true;
		int cnt = 0;
		bool flag;
		for (int i = 0; i < 5; i++) {
			flag = true;
			for (int j = 0; j < 5; j++) {
				if (!visited[i][j]) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
			flag = true;
			for (int j = 0; j < 5; j++) {
				if (!visited[j][i]) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		flag = true;
		for (int i = 0; i < 5; i++) {
			if (!visited[i][i]) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
		flag = true;
		for (int i = 0; i < 5; i++) {
			if (!visited[i][4 - i]) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
		if (cnt >= 3) {
			cout << b + 1;
			break;
		}
	}
	return 0;
}
