#include <iostream>
using namespace std;

int main() {
	int n;
	for (int i = 0; i < 3; i++) {
		int cnt = -1;
		for (int j = 0; j < 4; j++) {
			cin >> n;
			if (n == 0) cnt++;
		}
		if (cnt == -1) cnt = 4;
		cout << (char)('A' + cnt) << '\n';
	}
	return 0;
}
