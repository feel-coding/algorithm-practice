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
	char score;
	int bonus = 0;
	cin >> score;
	int sum = 0;
	if (score == 'O') {
		sum = 1;
		bonus = 1;
	}
	for (int i = 1; i < n; i++) {
		cin >> score;
		if (score == 'O') {
			sum += (i + 1 + bonus);
			bonus++;
		}
		else {
			bonus = 0;
		}
	}
	cout << sum;
	return 0;
}