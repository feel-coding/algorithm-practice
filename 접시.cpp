#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
	string str;
	vector<string> answer;
	cin >> str;
	char alphabet = 'a'; // 들어가야 할 알파벳
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= alphabet) {
			while (str[i] >= alphabet) {
				s.push(alphabet++);
				answer.push_back("push");
			}
			s.pop();
			answer.push_back("pop");
		}
		else {
			if (s.empty()) {
				cout << "impossible";
				return 0;
			}
			else if (s.top() == str[i]) {
				s.pop();
				answer.push_back("pop");
			}
			else {
				cout << "impossible";
				return 0;
			}
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}