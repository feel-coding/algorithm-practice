#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	int sum = 0;
	cin >> s;
	for (int i = 0; i < n; i++) {
		sum += stoi(s.substr(i, 1));
	}
	cout << sum;
	return 0;
}