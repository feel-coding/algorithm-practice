#include <iostream>
using namespace std;

int arr[105][105];
int n, k;

bool isRowUpward(int row) { // 오르막인지 체크
	for (int i = 0; i <= n - k; i++) {
		bool flag = true;
		for (int j = 0; j < k - 1; j++) {
			if (arr[row][i + j] + 1 >= arr[row][i + j + 1]) {
				flag = false;
				break;
			}
		}
		if (flag) return true;
	}
	return false;
}

bool isRowDownward(int row) { // 내리막인지 체크
	for (int i = 0; i <= n - k; i++) {
		bool flag = true;
		for (int j = 0; j < k - 1; j++) {
			if (arr[row][i + j] <= arr[row][i + j + 1] + 1) {
				flag = false;
				break;
			}
		}
		if (flag) return true;
	}
	return false;
}

bool isColUpward(int col) { // 특정 열이 오르막인지 체크
	for (int i = 0; i <= n - k; i++) {
		bool flag = true;
		for (int j = 0; j < k - 1; j++) {
			if (arr[i + j][col] + 1 >= arr[i + j + 1][col]) {
				flag = false;
				break;
			}
		}
		if (flag) return true;
	}
	return false;
}

bool isColDownward(int col) { // 특정 열이 내리막인지 체크
	for (int i = 0; i <= n - k; i++) {
		bool flag = true;
		for (int j = 0; j < k - 1; j++) {
			if (arr[i + j][col] <= arr[i + j + 1][col] + 1) {
				flag = false;
				break;
			}
		}
		if (flag) return true;
	}
	return false;
}

int main() {
	int testCase, cnt;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		cin >> n >> k;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			if (isRowUpward(i) || isRowDownward(i)) {
				cnt++;
			}
			if (isColUpward(i) || isColDownward(i)) {
				cnt++;
			}
		}
		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}