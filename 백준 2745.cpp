#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	int result = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] <= '9') {
			result += ((s[i] - '0') * pow(n, s.size() - i - 1));
		}
		else {
			result += ((s[i] - 'A' + 10) * pow(n, s.size() - i - 1));
		}
	}
	cout << result;
	return 0;
}