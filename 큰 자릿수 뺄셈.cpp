#include <iostream>
#include <string>
using namespace std;

int a[105];
int b[105];
int result[105];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	bool minusFlag = false;
	if (s2.size() > s1.size()) {
		minusFlag = true;
	}
	else if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); i++) {
			if (s2[i] > s1[i]) {
				minusFlag = true;
				break;
			}
		}
	}
	int index;
	if (minusFlag) {
		index = 104;
		for (int i = s2.size() - 1; i >= 0; i--) {
			a[index--] = s2[i] - '0';
		}
		index = 104;
		for (int i = s1.size() - 1; i >= 0; i--) {
			b[index--] = s1[i] - '0';
		}
	}
	else {
		index = 104;
		for (int i = s2.size() - 1; i >= 0; i--) {
			b[index--] = s2[i] - '0';
		}
		index = 104;
		for (int i = s1.size() - 1; i >= 0; i--) {
			a[index--] = s1[i] - '0';
		}
	}
	for (int i = 104; i >= 0; i--) {
		int temp = a[i] - b[i];
		if (temp < 0) {
			a[i - 1]--;
			a[i] += 10;
		}
		result[i] = a[i] - b[i];
	}
	bool notZero = false;
	if (minusFlag) cout << "-";
	for (int i = 0; i < 105; i++) {
		if (result[i] != 0) notZero = true;
		if (notZero) cout << result[i];
	}
	if (!notZero) cout << 0;
	return 0;
}
