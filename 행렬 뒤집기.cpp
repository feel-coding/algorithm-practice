#include <iostream>
using namespace std;

int arr[11][11] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			arr[j][i] = !arr[j][i];
			arr[i][j] = !arr[i][j];
		}
		arr[i][i] = !arr[i][i];
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
