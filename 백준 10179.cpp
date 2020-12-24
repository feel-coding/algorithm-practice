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
	double price;
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < n; i++) {
		cin >> price;
		cout << "$" << price * 0.8 << '\n';
	}
	return 0;
}