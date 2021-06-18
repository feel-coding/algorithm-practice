#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		bool flag = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (i == 1) flag = false;
		if (flag) cout << i << " ";
	}
}
