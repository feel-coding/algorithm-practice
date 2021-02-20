#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<bool> v(26);
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int result = 0;
		v = vector<bool>(26, false);
		for (int j = 0; j < s.size(); j++) {
			v[s[j] - 'A'] = true;
		}
		for (int j = 0; j < 26; j++) {
			if (!v[j]) {
				result += ('A' + j);
			}
		}
		cout << result << '\n';
	}
	return 0;
}