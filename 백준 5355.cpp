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
	int n;
	cin >> n;
	string s;
	double num;
	cout.precision(2);
	for (int i = 0; i < n; i++) {
		cin >> num;
		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				continue;
			}
			if (s[j] == '@') {
				num *= 3;
			}
			else if (s[j] == '%') {
				num += 5;
			}
			else if (s[j] == '#') {
				num -= 7;
			}
		}
		cout << fixed << num << '\n';
	}
	return 0;
}