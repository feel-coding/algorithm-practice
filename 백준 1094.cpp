#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int n;
	cin >> n;
	int count = 0;
	while (n != 0) {
		if (n == 64) {
			n -= 64;
		}
		else if (n >= 32) {
			n -= 32;
		}
		else if (n >= 16) {
			n -= 16;
		}
		else if (n >= 8) {
			n -= 8;
		}
		else if (n >= 4) {
			n -= 4;
		}
		else if (n >= 2) {
			n -= 2;
		}
		else if (n >= 1) {
			n -= 1;
		}
		count++;
	}
	cout << count;
	return 0;
}