#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	int cnt = 0;
	while (true) {
		getline(cin, s);
		if (s == "#")
			break;
		cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}