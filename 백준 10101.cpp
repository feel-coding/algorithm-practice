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
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c != 180) {
		cout << "Error";
	}
	else if (a == b && b == c) {
		cout << "Equilateral";
	}
	else if (a == b || b == c || c == a) {
		cout << "Isosceles";
	}
	else {
		cout << "Scalene";
	}
	return 0;
}