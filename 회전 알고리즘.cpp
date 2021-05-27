#include <iostream>
using namespace std;

int main() {
	int n, q;
	int arr[105];
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int d, y;
	int x = 0;
	for (int i = 0; i < q; i++) {
		cin >> d >> y;
		y %= n;
		if (d == 2) {
			x = (x - y + n) % n;
			cout << arr[x] << '\n';
		}
		else {
			x = (x + y) % n;
			cout << arr[x] << '\n';
		}
	}
	return 0;
}
