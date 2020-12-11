#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> v(26, 0);
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v[s[0] - 97]++;
	}
	vector<char> names;
	for (int i = 0; i < 26; i++) {
		if (v[i] >= 5) {
			names.push_back(i + 97);
		}
	}
	if (names.size() == 0) {
		cout << "PREDAJA";
	}
	else {
		for (int i = 0; i < names.size(); i++) {
			cout << names[i];
		}
	}
	return 0;
}