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
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[s.size() - 1] % 2 == 0) {
			cout << "even\n";
		}
		else {
			cout << "odd\n";
		}
	}
	return 0;
}