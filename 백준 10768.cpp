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
	int month, date;
	cin >> month >> date;
	if (month < 2) {
		cout << "Before";
	}
	else if (month > 2) {
		cout << "After";
	}
	else {
		if (date < 18) {
			cout << "Before";
		}
		else if (date > 18) {
			cout << "After";
		}
		else {
			cout << "Special";
		}
	}
	return 0;
}