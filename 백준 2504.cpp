#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string paren;
	stack<int> s;
	cin >> paren;
	for (int i = 0; i < paren.size(); i++) {
		if (paren[i] == '(') {
			s.push(-1);
		}
		else if (paren[i] == '[') {
			s.push(-2);
		}
		else if (paren[i] == ')') {
			if (!s.empty() && s.top() == -1) {
				s.pop();
			}
			else {
				cout << 0;
				return 0;
			}
		}
		else if (paren[i] == ']') {
			if (!s.empty() && s.top() == -2) {
				s.pop();
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}
	if (!s.empty()) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < paren.size(); i++) {
		if (paren[i] == '(') {
			s.push(-1);
		}
		else if (paren[i] == '[') {
			s.push(-2);
		}
		else if (paren[i] == ')') {
			int num = 0;
			int temp = s.top();
			s.pop();
			while (temp != -1) {
				num += temp;
				temp = s.top();
				s.pop();
			}
			if (num == 0) num = 2;
			else num *= 2;
			s.push(num);
		}
		else if (paren[i] == ']') {
			int num = 0;
			int temp = s.top();
			s.pop();
			while (temp != -2) {
				num += temp;
				temp = s.top();
				s.pop();
			}
			if (num == 0) num = 3;
			else num *= 3;
			s.push(num);
		}
	}
	int result = 0;
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result;
	return 0;
}