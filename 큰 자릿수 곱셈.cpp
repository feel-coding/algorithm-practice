#include <iostream>
#include <string>
using namespace std;

int result[205];
int a[205];
int b[205];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int index = 204;
	for (int i = s1.size() - 1; i >= 0; i--) {
		a[index--] = s1[i] - '0';
	}
	index = 204;
	for (int i = s2.size() - 1; i >= 0; i--) {
		b[index--] = s2[i] - '0';
	}
	for (int i = 204; i >= 0; i--) {
		int temp[205] = { 0 };
		index = i;
		int plus = 0;
		int tempNum;
		for (int j = 204; j >= 0; j--) {
			tempNum = b[i] * a[j] + plus;
			if (index >= 0) {
				temp[index--] = tempNum % 10;
				plus = tempNum / 10;
			}
		}
		plus = 0;
		for (int j = 204; j >= 0; j--) {
			tempNum = result[j] + temp[j] + plus;
			result[j] = tempNum % 10;
			plus = tempNum / 10;
		}
	}
	bool started = false;
	for (int i = 0; i < 205; i++) {
		if (result[i] != 0) started = true;
		if (started) cout << result[i];
	}
	if (!started) cout << 0;
	return 0;
}
