#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int total = 0;
	string num = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			num += s[i];
		}
		else {
			total += stoi(num);
			num = "";
		}
	}
	total += stoi(num);
	cout << total;
	return 0;
}
