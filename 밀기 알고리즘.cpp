#include <iostream>
using namespace std;

int arr[1005][1005];

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int f, x, y;
	for (int i = 0; i < q; i++) {
		cin >> f >> x >> y;
		if (x == 1) { // 오른쪽으로 밀기
			for (int r = 0; r < y; r++) {
				int temp = arr[f][m - 1];
				for (int j = m - 1; j >= 1; j--) {
					arr[f][j] = arr[f][j - 1];
				}
				arr[f][0] = temp;
			}
		}
		else {
			for (int r = 0; r < y; r++) {
				int temp = arr[f][0];
				for (int j = 0; j < m - 1; j++) {
					arr[f][j] = arr[f][j + 1];
				}
				arr[f][m - 1] = temp;
			}
		}
		for (int j = 0; j < m; j++) {
			cout << arr[f][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
