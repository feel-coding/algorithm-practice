#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int num = 1;
	bool flag = false;
	while (num <= n) {
		if (num == n) {
			flag = true;
			break;
		}
		num *= 2;
	}
	cout << flag;
	return 0;
}