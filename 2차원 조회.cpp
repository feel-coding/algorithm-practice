#include <iostream>
using namespace std;

int main() {
	int arr[105][105];
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		arr[i][0] = -1;
		arr[i][m + 1] = -1;
	}
	for (int i = 0; i <= m + 1; i++) {
		arr[0][i] = -1;
		arr[n + 1][i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i - 1][j] == arr[i][j] || arr[i + 1][j] == arr[i][j] || arr[i][j - 1] == arr[i][j] || arr[i][j + 1] == arr[i][j]) {
				cout << 1 << " ";
			}
			else cout << 0 << " ";
		}
		cout << '\n';
	}
	return 0;
}
