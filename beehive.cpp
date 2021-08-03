#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	int k = 7;
	int gap = 6;
	for (int i = 2; ; i++) {
		if (n <= k) {
			cout << i;
			break;
		}
		gap += 6;
		k += gap;
	}
	return 0;
}
