#include <iostream>
using namespace std;

int main() {
	int m;
	cin >> m;
	int total = 0;
	for (int i = 1; ; i++) {
		total += i;
		if (total >= m) {
			cout << i;
			break;
		}
	}
	return 0;
}
