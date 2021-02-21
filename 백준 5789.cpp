#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[s.size() / 2 - 1] != s[s.size() / 2]) {
			cout << "Do-it-Not\n";
		}
		else {
			cout << "Do-it\n";
		}
	}
	return 0;
}