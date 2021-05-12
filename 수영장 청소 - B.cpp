#include <iostream>
using namespace std;

int arr[10][10];
int n, m;
int row, col, type;

void toRightClean() {
	for (int i = col + 1; i < m; i++) {
		if (arr[row][i] == 6) {
			break;
		}
		arr[row][i] = 8;
	}
}

void toLeftClean() {
	for (int i = col - 1; i >= 0; i--) {
		if (arr[row][i] == 6) {
			break;
		}
		arr[row][i] = 8;
	}
}

void toUpClean() {
	for (int i = row - 1; i >= 0; i--) {
		if (arr[i][col] == 6) {
			break;
		}
		arr[i][col] = 8;
	}
}

void toDownClean() {
	for (int i = row + 1; i < n; i++) {
		if (arr[i][col] == 6) {
			break;
		}
		arr[i][col] = 8;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				row = i;
				col = j;
				type = arr[i][j];
			}
		}
	}
	if (type == 1) {
		toUpClean();
	}
	else if (type == 2) {
		toUpClean();
		toDownClean();
	}
	else if (type == 3) {
		toUpClean();
		toRightClean();
	}
	else if (type == 4) {
		toUpClean();
		toLeftClean();
		toRightClean();
	}
	else if (type == 5) {
		toUpClean();
		toDownClean();
		toLeftClean();
		toRightClean();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
