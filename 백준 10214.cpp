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
	int testCase;
	cin >> testCase;
	int y, k;
	int ySum = 0;
	int kSum = 0;
	for (int t = 0; t < testCase; t++) {
		ySum = 0;
		kSum = 0;
		for (int i = 0; i < 9; i++) {
			cin >> y >> k;
			ySum += y;
			kSum += k;
		}
		if (ySum > kSum) {
			cout << "Yonsei\n";
		}
		else if (kSum > ySum) {
			cout << "Korea\n";
		}
		else {
			cout << "Draw\n";
		}
	}
	return 0;
}