#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int num;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		bool flag = true;
		for (int j = 2; j <= sqrt(num); j++) {
			if (num % j == 0) {
				flag = false;
				break;
			}
		}
		if (num == 1) flag = false;
		if (flag) cnt++;
	}
	cout << cnt;
	return 0;
}
