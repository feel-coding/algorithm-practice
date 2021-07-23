#include <iostream>
#include <string>
using namespace std;

int a[105] = { 0 };
int b[105] = { 0 };
int result[105] = { 0 };

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int index = 104;
	for (int i = s1.size() - 1; i >= 0; i--) {
		a[index--] = s1[i] - '0';
	}
	index = 104;
	for (int i = s2.size() - 1; i >= 0; i--) {
		b[index--] = s2[i] - '0';
	}
	int plus = 0;
	for (int i = 104; i >= 0; i--) {
		int temp = a[i] + b[i] + plus;
		plus = temp / 10;
		result[i] = temp % 10;
	}
	bool started = false;
	for (int i = 0; i < 105; i++) {
		if (result[i] != 0) started = true;
		if (started) {
			cout << result[i];
		}
	}
	if (!started) cout << 0;
	return 0;
}
