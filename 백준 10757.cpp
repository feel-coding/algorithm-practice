#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	if (a.size() > b.size()) {
		string s = "";
		for (int i = 0; i < a.size() - b.size(); i++) {
			s.append("0");
		}
		b = s + b;
	}
	else if (b.size() > a.size()) {
		string s = "";
		for (int i = 0; i < b.size() - a.size(); i++) {
			s.append("0");
		}
		a = s + a;
	}
	string answer = "";
	int num = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		int sum = a[i] + b[i] - 96 + num;
		num = sum / 10;
		sum %= 10;
		answer.append(to_string(sum));
	}
	while (num > 0) {
		int sum = num % 10;
		num /= 10;
		answer.append(to_string(sum));
	}
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i];
	}
	return 0;
}
