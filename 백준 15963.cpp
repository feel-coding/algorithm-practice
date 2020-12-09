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
	string n, m;
	cin >> n >> m;
	if (n == m) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}