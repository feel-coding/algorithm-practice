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
	string s;
	while (true) {
		cin >> s;
		if (s == "0") {
			break;
		}
		bool flag = true;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - 1 - i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}