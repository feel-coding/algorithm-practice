#include <iostream>
using namespace std;

int arr[105][105];
int temp[105][105];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int main() {
	int n, m, t;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
		}
	}
	cin >> t;
	for (int s = 0; s < t; s++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 0; k < 4; k++) {
					int row = i + dr[k];
					int col = j + dc[k];
					arr[row][col] += temp[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
