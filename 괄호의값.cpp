#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string paren;
	cin >> paren;
	stack<int> s;
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
			int temp = s.top();
			s.pop();
			if (temp == -1) {
				s.push(2);
			}
			else {
				int num = temp;
				temp = s.top();
				s.pop();
				while (temp != -1) {
					num += temp;
					temp = s.top();
					s.pop();
				}
				s.push(num * 2);
			}
		}
		else if (paren[i] == ']') {
			int temp = s.top();
			s.pop();
			if (temp == -2) {
				s.push(3);
			}
			else {
				int num = temp;
				temp = s.top();
				s.pop();
				while (temp != -2) {
					num += temp;
					temp = s.top();
					s.pop();
				}
				s.push(num * 3);
			}
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
