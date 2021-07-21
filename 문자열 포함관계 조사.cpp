#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i <= a.size() - b.size(); i++) {
		if (a.substr(i, b.size()) == b) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
