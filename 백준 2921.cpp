#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 2 * n; i >= 1; i--) {
		for (int j = 0; j <= i / 2; j++) {
			if (i - j <= n) cnt += i;
		}
	}
	cout << cnt;
	return 0;
}