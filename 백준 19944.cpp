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
	int n, m;
	cin >> n >> m;
	if (m == 1 || m == 2) {
		cout << "NEWBIE!";
	}
	else if (m <= n) {
		cout << "OLDBIE!";
	}
	else {
		cout << "TLE!";
	}
	return 0;
}