#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b, c, money;
	int maxMoney = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a == b && b == c) {
			money = 10000 + a * 1000;
		}
		else if (a == b || a == c) {
			money = 1000 + a * 100;
		}
		else if (b == c) {
			money = 1000 + b * 100;
		}
		else {
			money = max(a, max(b, c)) * 100;
		}
		if (money > maxMoney) maxMoney = money;
	}
	cout << maxMoney;
	return 0;
}
