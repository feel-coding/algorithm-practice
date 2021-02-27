#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string answer = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			answer += "000";
		}
		else if (s[i] == '1') {
			answer += "001";
		}
		else if (s[i] == '2') {
			answer += "010";
		}
		else if (s[i] == '3') {
			answer += "011";
		}
		else if (s[i] == '4') {
			answer += "100";
		}
		else if (s[i] == '5') {
			answer += "101";
		}
		else if (s[i] == '6') {
			answer += "110";
		}
		else if (s[i] == '7') {
			answer += "111";
		}
	}
	bool started = false;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] != '0') started = true;
		if (started) cout << answer[i];
	}
	if (!started) cout << 0;
	return 0;
}
