#include <iostream>
using namespace std;

int arr[105][105];

int main() {
	int n, y, x;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> y >> x;
		if (arr[y][x] == 0) {
			arr[y][x] = 1;
			sum += i;
		}
	}
	cout << sum;
	return 0;
}
