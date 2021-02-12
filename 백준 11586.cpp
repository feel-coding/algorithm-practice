#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	string arr[110];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << '\n';
		}
	}
	else if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				cout << arr[i][j];
			}
			cout << '\n';
		}
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			cout << arr[i] << '\n';
		}
	}
	return 0;
}
