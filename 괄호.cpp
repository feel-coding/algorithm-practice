#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string paren;
	stack<char> s;
	cin >> paren;
	for (int i = 0; i < paren.size(); i++) {
		if (paren[i] == '(') s.push(paren[i]);
		else {
			if (!s.empty()) s.pop();
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	if (s.empty()) cout << "YES";
	else cout << "NO";
	return 0;
}
