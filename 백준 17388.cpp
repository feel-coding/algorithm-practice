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
	int s, k, h;
	cin >> s >> k >> h;
	if (s + k + h >= 100) {
		cout << "OK";
	}
	else {
		if (s < k && s < h) {
			cout << "Soongsil";
		}
		else if (k < s && k < h) {
			cout << "Korea";
		}
		else {
			cout << "Hanyang";
		}
	}
	return 0;
}