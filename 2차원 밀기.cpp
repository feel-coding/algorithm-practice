#include <iostream>
using namespace std;

int arr[105][105];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int temp = arr[0][m - 1];
	for (int i = m - 1; i >= 1; i--) {
		arr[0][i] = arr[0][i - 1];
	}
	for (int i = 0; i < n - 1; i++) {
		arr[i][0] = arr[i + 1][0];
	}
	for (int i = 0; i < m - 1; i++) {
		arr[n - 1][i] = arr[n - 1][i + 1];
	}
	for (int i = n - 1; i >= 1; i--) {
		arr[i][m - 1] = arr[i - 1][m - 1];
	}
	arr[1][m - 1] = temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
