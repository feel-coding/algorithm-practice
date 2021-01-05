#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector<string> v;

void compress(int row, int col, int size) {
	if (size == 1) {

	}
	char first = v[row][col];
	bool flag = true;
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (v[i][j] != first) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	if (!flag) {
		cout << '(';
		compress(row, col, size / 2);
		compress(row, col + size / 2, size / 2);
		compress(row + size / 2, col, size / 2);
		compress(row + size / 2, col + size / 2, size / 2);
		cout << ')';
	}
	else {
		cout << first;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	v = vector<string>(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	compress(0, 0, n);
	return 0;
}