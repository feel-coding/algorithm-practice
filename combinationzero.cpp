#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int twoCount = 0;
	int fiveCount = 0;
	for (int i = n; i > n - m; i--) {
		int num = i;
		while (num % 5 == 0) {
			fiveCount++;
			num /= 5;
		}
		while (num % 2 == 0) {
			twoCount++;
			num /= 2;
		}
	}
	for (int i = m; i > 1; i--) {
		int num = i;
		while (num % 5 == 0) {
			fiveCount--;
			num /= 5;
		}
		while (num % 2 == 0) {
			twoCount--;
			num /= 2;
		}
	}
	cout << min(twoCount, fiveCount);
	return 0;
}
