#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			bool flag = true;
			for (int j = 2; j <= sqrt(i); j++) {
				if (i % j == 0) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
