#include <iostream>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	int x, y;
	for (int t = 0; t < testCase; t++) {
		cin >> x >> y;
		y = y - x;
		x = 0;
		int location = 0;
		int cnt = 0;
		for (int i = 1; ; i++) {
			if (y - location * 2 == 0) {
				break;
			}
			else if (y - location * 2 <= i) {
				cnt++;
				break;
			}
			else if (y - (location + i) * 2 < 0) {
				cnt += 2;
				break;
			}
			cnt += 2;
			location += i;
		}
		cout << cnt << '\n';
	}
	return 0;
}
