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
	int x, y;
	int q1 = 0;
	int q2 = 0;
	int q3 = 0;
	int q4 = 0;
	int axis = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x == 0 || y == 0) {
			axis++;
		}
		else if (x > 0 && y > 0) {
			q1++;
		}
		else if (x > 0 && y < 0) {
			q4++;
		}
		else if (x < 0 && y < 0) {
			q3++;
		}
		else {
			q2++;
		}
	}
	cout << "Q1: " << q1 << endl;
	cout << "Q2: " << q2 << endl;
	cout << "Q3: " << q3 << endl;
	cout << "Q4: " << q4 << endl;
	cout << "AXIS: " << axis;
	return 0;
}