#include <iostream>
using namespace std;

int arr[100][100] = { 0 };

int main() {
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (int i = b; i < b + 10; i++) {
			for (int j = a; j < a + 10; j++) {
				arr[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}