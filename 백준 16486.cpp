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
	int d1, d2;
	cin >> d1 >> d2;
	cout << fixed;
	cout.precision(7);
	cout << d1 * 2 + 2 * d2 * 3.141592;
	return 0;
}