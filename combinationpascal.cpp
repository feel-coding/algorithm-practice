#include <iostream>
using namespace std;

int main() {
	int arr[35][35] = { 0 };
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	cout << arr[n][m];
	return 0;
}
