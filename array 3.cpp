#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int num = 1;
	int arr[105][105];
	for (int r = 1; r <= n; r++) {
		for (int i = 0; i < r; i++) {
			arr[i][r - i - 1] = num++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
