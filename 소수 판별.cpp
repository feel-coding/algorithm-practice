#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int flag = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			flag = false;
			break;
		}
	}
	if (n == 1) flag = false;
	cout << (flag ? "YES" : "NO");
	return 0;
}
